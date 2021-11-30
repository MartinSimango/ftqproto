package main

import (
	"flag"
	"fmt"
	"io/ioutil"
	"log"
	"os"
	"strings"

	"github.com/MartinSimango/ftqproto/tools/cmd/module"
	"gopkg.in/yaml.v2"
)

func main() {

	outputDir := flag.String("o", ".", "output dir")
	programName := os.Args[0]

	flag.Usage = func() {
		usage := "usage: " + programName + " [-o output dir] configFile"
		fmt.Println(usage)
	}

	flag.Parse()

	args := flag.Args()

	if len(args) == 0 {
		flag.Usage()
		os.Exit(1)
	}

	yamlFileName := args[0]

	modulesDirectory := *outputDir
	if _, err := os.Stat(modulesDirectory); err != nil {
		if os.IsNotExist(err) {
			log.Printf("%v ", err)
			os.Exit(1)
		}
	}

	yamlSchema := &module.ModuleDefinition{}
	yamlFile, err := ioutil.ReadFile(yamlFileName)
	if err != nil {
		log.Printf("%v ", err)
		os.Exit(1)
	}
	err = yaml.Unmarshal(yamlFile, yamlSchema)
	if err != nil {
		log.Fatalf("Unmarshal: %v", err)
		os.Exit(1)
	}

	for _, mod := range yamlSchema.Modules {
		modDirectory := modulesDirectory + "/" + mod.Name
		makefile := strings.TrimSpace(module.MakeMakefile(mod))
		os.RemoveAll(modDirectory)
		err = os.Mkdir(modDirectory, 0755)
		if err != nil {
			fmt.Println("Unable to create directory: %v", err)
		}
		err = ioutil.WriteFile(modDirectory+"/Makefile", []byte(makefile), 0755)
		if err != nil {
			fmt.Printf("Unable to write file: %v", err)
		}

	}
}
