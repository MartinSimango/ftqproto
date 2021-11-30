#! /bin/sh

# Generate the module makefiles
rm -rf modules && mkdir -p modules
gen-module -o modules modules.yaml

make build