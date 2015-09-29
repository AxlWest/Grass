#pragma once

#include "Drawable.h"

/*****************************************************************************************
*Loads obj file - limited to vertices, faces, normals, texture maps
*loads to object structure as defined in .h file
******************************************************************************************/


#define MAX_VERTICES 8000 // Max number of vertices (for each object)
#define MAX_POLYGONS 8000 // Max number of polygons (for each object)
#define MAX_NORMALS 8000 // Max number of polygons (for each object)

// Our vertex type
typedef struct{
    float x,y,z;
}vertex_type;

// Our normal type
typedef struct{
    float i,j,k;
}normcoord_type;

// The polygon (triangle), 3 numbers that aim 3 vertices
typedef struct{
    int v[3],t[3],n[3];
}polygon_type;

// The mapcoord type, 2 texture coordinates for each vertex
typedef struct{
    float u,v;
}mapcoord_type;

// The object type
class Object_type : public Drawable
{
	public :

		int id_texture;	
		Object_type(){}
		~Object_type(){}
		int objloader(char *p_filename); 
		int objdatadisplay();
		void render();
		virtual void draw() ;
		virtual void update() ;

	private :

		char name[20];
		int vertices_qty;
		int polygons_qty;
		int mapcoord_qty;
		int normcoord_qty;

		vertex_type vertex[MAX_VERTICES]; 
		mapcoord_type mapcoord[MAX_VERTICES];
		normcoord_type normcoord[MAX_NORMALS];
		polygon_type polygon[MAX_POLYGONS];

} ;


//Gorden Dickers
/*************************************************************/
