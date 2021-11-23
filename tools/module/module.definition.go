package module

type ModuleDefinition struct {
	Modules []struct {
		Name               string `yaml:"name"`
		LibraryName        string `yaml:"libraryName"`
		Compiler           string `yaml:"compiler"`
		Flags              string `yaml:"flags,omitempty"`
		InstallationFolder string `yaml:"installationFolder"`
		Depedencies        struct {
			Domain  []string `yaml:"domain"`
			Driver  []string `yaml:"driver"`
			Adapter []string `yaml:"adapter"`
			Usecase []string `yaml:"usecase"`
		} `yaml:"depedencies,omitempty"`
		MakeRules []struct {
			Name         string   `yaml:"name"`
			Dependencies []string `yaml:"dependencies"`
			Commands     []string `yaml:"commands"`
		} `yaml:"makeRules,omitempty"`
	} `yaml:"modules"`
}
