#pragma once
#include <Windows.h>
#include <gl\glut.h>
#include "triangle_mesh.h"
#include "vectors.h"
#include "matrix.h"
#include "arg_parser.h"

class Spline{
public:
	int vertices_num;
	Vec3f* vertices_array;

	Spline() {}
	Spline(int vertices_num){
		this->vertices_num = vertices_num;
		vertices_array = new Vec3f[1000];
	}
	virtual ~Spline(){
		delete[] vertices_array;
	}
	// ���ڻ�ͼ��FOR VISUALIZATION
	virtual void Paint(ArgParser* args){}
	// ����ʵ����������ת����FOR CONVERTING BETWEEN SPLINE TYPES
	virtual void OutputBezier(FILE* file) = 0;
	virtual void OutputBSpline(FILE* file) = 0;
	// ���ڵõ����Ƶ��FOR CONTROL POINT PICKING
	virtual int getNumVertices(){
		return vertices_num;
	}
	virtual Vec3f getVertex(int i){
		return vertices_array[i];
	}
	virtual void set(int index, Vec3f vector){
		vertices_array[index] = vector;
	}
	// ���ڱ༭������FOR EDITING OPERATIONS
	virtual void moveControlPoint(int selectedPoint, float x, float y){
		Vec3f v = Vec3f(x, y, 0);
		vertices_array[selectedPoint] = v;
	}
	virtual void addControlPoint(int selectedPoint, float x, float y){
		Vec3f v = Vec3f(x, y, 0);
		vertices_array[selectedPoint] = v;
		vertices_num++;
	}
	virtual void deleteControlPoint(int selectedPoint){
		for (int i = selectedPoint;  i < vertices_num - 1; i++){
			vertices_array[selectedPoint] = vertices_array[selectedPoint + 1];
		}
		vertices_num--;
	}
	// ���ڲ��������ε�FOR GENERATING TRIANGLES
	virtual TriangleMesh* OutputTriangles(ArgParser* args){
		return 0;
	}
};