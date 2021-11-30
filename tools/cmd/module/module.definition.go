package module

type ModuleDependencies struct {
	Domain  []string `yaml:"domain"`
	Driver  []string `yaml:"driver"`
	Adapter []string `yaml:"adapter"`
	Usecase []string `yaml:"usecase"`
}

type Module struct {
	Name               string             `yaml:"name"`
	LibraryName        string             `yaml:"libraryName"`
	Compiler           string             `yaml:"compiler"`
	Flags              string             `yaml:"flags,omitempty"`
	InstallationFolder string             `yaml:"installationFolder"`
	Dependencies       ModuleDependencies `yaml:"depedencies,omitempty"`
	MakeRules          []MakeRule         `yaml:"makeRules,omitempty"`
}

type MakeRule struct {
	Name         string   `yaml:"name"`
	Dependencies string   `yaml:"dependencies"`
	Commands     []string `yaml:"commands"`
}

type ModuleDefinition struct {
	Modules []Module `yaml:"modules"`
}
