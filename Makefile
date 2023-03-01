storage.zip:
	zip -r storage.zip storage/


init: 
	g++ -o ./det.exe ./scripts/det.cpp
	g++ -o ./sample.exe ./scripts/sample.cpp
	mpicxx -o ./exp.exe ./scripts/exp.cpp

	rm -r storage
	mkdir storage

	mkdir storage/meshes
	mkdir storage/meshes/det
	mkdir storage/meshes/rand
	mkdir storage/meshes/rand/mesh
	mkdir storage/meshes/rand/mesh0
	mkdir storage/meshes/rand/mesh1

	mkdir storage/paraview

	mkdir storage/solutions
	mkdir storage/solutions/det
	mkdir storage/solutions/rand
	mkdir storage/solutions/rand/sig
	mkdir storage/solutions/rand/u
	mkdir storage/solutions/rand/v