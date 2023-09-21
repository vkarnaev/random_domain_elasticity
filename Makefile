init: 
	g++ -o ./det.exe ./scripts/det.cpp
	g++ -o ./sample.exe ./scripts/sample.cpp
	mpicxx -o ./exp.exe ./scripts/exp.cpp

	rm -r storage
	mkdir storage

	mkdir storage/ev
	mkdir storage/ev/eV1
	mkdir storage/ev/eV2

	mkdir storage/meshes
	mkdir storage/meshes/det
	mkdir storage/meshes/rand
	mkdir storage/meshes/rand/mesh
	mkdir storage/meshes/rand/mesh0
	mkdir storage/meshes/rand/mesh1

	mkdir storage/solutions
	mkdir storage/solutions/det
	mkdir storage/solutions/rand
	mkdir storage/solutions/rand/sig
	mkdir storage/solutions/rand/u
	mkdir storage/solutions/rand/v

	rm -r exp
	mkdir -p exp

	mkdir -p exp/sg
	mkdir -p exp/sg/l1
	mkdir -p exp/sg/l2
	mkdir -p exp/sg/l3
	mkdir -p exp/sg/l4
	mkdir -p exp/sg/l5
	mkdir -p exp/sg/l6
	mkdir -p exp/sg/l7

	mkdir -p exp/sobol
	mkdir -p exp/sobol/l1
	mkdir -p exp/sobol/l2
	mkdir -p exp/sobol/l3
	mkdir -p exp/sobol/l4
	mkdir -p exp/sobol/l5
	mkdir -p exp/sobol/l6
	mkdir -p exp/sobol/l5
	mkdir -p exp/sobol/l7
	mkdir -p exp/sobol/l8
	mkdir -p exp/sobol/l9
	mkdir -p exp/sobol/l10

	mkdir -p exp/iplr2
	mkdir -p exp/iplr2/l1
	mkdir -p exp/iplr2/l2
	mkdir -p exp/iplr2/l3
	mkdir -p exp/iplr2/l4
	mkdir -p exp/iplr2/l5
	mkdir -p exp/iplr2/l6
	mkdir -p exp/iplr2/l5
	mkdir -p exp/iplr2/l7
	mkdir -p exp/iplr2/l8
	mkdir -p exp/iplr2/l9
	mkdir -p exp/iplr2/l10

	mkdir -p exp/halton
	mkdir -p exp/halton/l1
	mkdir -p exp/halton/l2
	mkdir -p exp/halton/l3
	mkdir -p exp/halton/l4
	mkdir -p exp/halton/l5
	mkdir -p exp/halton/l6
	mkdir -p exp/halton/l5
	mkdir -p exp/halton/l7
	mkdir -p exp/halton/l8
	mkdir -p exp/halton/l9
	mkdir -p exp/halton/l10



