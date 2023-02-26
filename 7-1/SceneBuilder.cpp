///
///	This class is designed to be the one place where all
///	shapes are created. It utilizes the UShapeBuilder class
///	to build the shapes into GLMesh structs. The individual
///	shape structs are then added to a vector called "scene" that is
///	then passed to the main render method in the source class
///	(5-3 Texturing a Pyramid.cpp)
///
///
///	Follow the standard shown below in the <summary> to see
///	how to build a shape
///




#include "SceneBuilder.h"
#include "ShapeBuilder.h"
#include "Mesh.h"

using namespace std;


void SceneBuilder::UBuildScene(vector<GLMesh>& scene)
{




	// seed the rand() function once
	srand(time(nullptr));


	/// <summary>
	///
	///BUILDING A SHAPE:
	///To build a shape, follow the following standard:
	///
	///		GLMesh <glmesh_name>
	///		<glmesh_name>.p = {
	///		red float, green float, blue float, alpha float,
	///		x scale float, y scale float, z scale float,
	///		x rotation degrees float, 1.0f, 0.0f, 0.0f,
	///		y rotation degrees float, 0.0f, 1.0f, 0.0f,
	///		z rotation degrees float, 0.0f, 0.0f, 1.0f,
	///		x translate float, y translate float, z translate float,
	///		x texture scale float, y texture scale float
	///		};
	///		<glmesh_name>.texFilename = "textures\\[filename.filetype]";
	///		<glmesh_name>.length = float;
	///		<glmesh_name>.height = float;
	///		<glmesh_name>.radius = float;
	///		<glmesh_name>.number_of_sides = float;
	///		ShapeBuilder::<ShapeBuilderMethod>(<glmesh_name>);
	///		**OR**
	///		ShapeBuilder::<ShapeBuild "Rainbow" Shape>(<glmesh_name>, rand() % 100 + 1);
	///		scene.push_back(<glmesh_name>);
	///
	///
	///
	///		See below for an example using the UBuildCone() method
	///
	///
	/// </summary>
	/// <param name="scene"></param>






	// DESK
	GLMesh plan_gMesh01;
	plan_gMesh01.p = {
		1.0f, 1.0f, 1.0f, 1.0f,				// color r, g, b a
		15.0f, 2.0f, 10.0f,					// scale x, y, z
		0.0f, 1.0f, 0.0f, 0.0f,				// x amount of rotation, rotate x, y, z
		45.0f, 0.0f, 1.0f, 0.0f,				// y amount of rotation, rotate x, y, z
		0.0f, 0.0f, 0.0f, 1.0f,				// z amount of rotation, rotate x, y, z
		1.0f, 0.0f, 0.0f,					// translate x, y, z
		2.0f, 2.0f
	};
	plan_gMesh01.texFilename = "textures\\desk.png";
	ShapeBuilder::UBuildPlane(plan_gMesh01);
	scene.push_back(plan_gMesh01);





	//HOLLOW CYLINDER
	GLMesh hollow_cyl;
	hollow_cyl.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		2.0f,	2.0f,	2.0f,
		0.0f,	1.0f,	0.0f,	0.0f,
		-90.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		-4.0f,	0.0f,	3.0f,
		1.0f,	1.0f
	};
	hollow_cyl.texFilename = "textures\\snhu.png";
	hollow_cyl.innerRadius = 0.45f;
	hollow_cyl.radius = 0.5f;
	hollow_cyl.height = 1.0f;
	hollow_cyl.number_of_sides = 144.0f;
	ShapeBuilder::UBuildHollowCylinder(hollow_cyl);
	scene.push_back(hollow_cyl);

	// COFFEE
	GLMesh coffee;
	coffee.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		2.0f,	2.0f,	2.0f,
		0.0f,	1.0f,	0.0f,	0.0f,
		180.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		-4.0f,	1.9f,	5.0f,
		1.0f,	1.0f
	};
	coffee.radius = 0.45f;
	coffee.number_of_sides = 144.0f;
	coffee.texFilename = "textures\\coffee.png";
	ShapeBuilder::UBuildCircle(coffee);
	scene.push_back(coffee);


	// HANDLE
	GLMesh handle;
	handle.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		2.0f,	2.0f,	2.0f,
		90.0f,	1.0f,	0.0f,	0.0f,
		0.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	0.0f,	1.0f,
		-5.0f,	2.0f,	4.0f,
		1.0f,	1.0f
	};
	handle.texFilename = "textures\\white.png";
	handle.innerRadius = 0.3f;
	handle.radius = 0.4f;
	handle.height = 0.1f;
	handle.number_of_sides = 144.0f;
	ShapeBuilder::UBuildHollowCylinder(handle);
	scene.push_back(handle);

	//phone
	GLMesh phone;
	phone.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		6.0f,	0.2f,	3.0f,
		0.0f,	1.0f,	0.0f,	0.0f,
		-45.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	1.0f,	1.0f,
		10.0f,	0.0f,	-10.0f,
		1.0f,	1.0f
	};
	phone.texFilename = "textures\\phone.png";
	ShapeBuilder::UBuildCube(phone);
	scene.push_back(phone);

	//laptop
	GLMesh laptop;
	laptop.p = {
		1.0f,	1.0f,	1.0f,	1.0f,
		8.0f,	0.3f,	13.0f,
		0.0f,	1.0f,	0.0f,	0.0f,
		-45.0f,	0.0f,	1.0f,	0.0f,
		0.0f,	0.0f,	1.0f,	1.0f,
		2.0f,	0.0f,	-2.0f,
		4.0f,	2.0f
	};
	laptop.texFilename = "textures\\grey.png";
	ShapeBuilder::UBuildCube(laptop);
	scene.push_back(laptop);



}

