#include "Matrix3.h"

Matrix3::Matrix3()
{
	m = 3; n = 3;

	matrix[0][0] = 1.0f; matrix[0][1] = 0.0f; matrix[0][2] = 0.0f;
	matrix[1][0] = 0.0f; matrix[1][1] = 1.0f; matrix[1][2] = 0.0f;
	matrix[2][0] = 0.0f; matrix[2][1] = 0.0f; matrix[2][2] = 1.0f;

}


Matrix3::Matrix3(float Xx, float Xy, float Xz, float Yx, float Yy, float Yz, float Zx, float Zy, float Zz)
{
	m = 3; n = 3;
	matrix[0][0] = Xx; matrix[0][1] = Yx; matrix[0][2] = Zx;
	matrix[1][0] = Xy; matrix[1][1] = Yy; matrix[1][2] = Zy;
	matrix[2][0] = Xz; matrix[2][1] = Yz; matrix[2][2] = Zz;
}
/*
Matrix3::Matrix3(Vector3 v3) {
	//Translation matrix
	m = 3, n = 3;
	matrix[0][0] = 1; matrix[0][1] = 0; matrix[0][2] = v3.x;
	matrix[1][0] = 0; matrix[1][1] = 1; matrix[1][2] = v3.y;
	matrix[2][0] = 0; matrix[2][1] = 0; matrix[2][2] = 1;
}
*/
Matrix3::Matrix3(Vector3 v1, Vector3 v2, Vector3 v3)
{
	m = 3; n = 3;

	matrix[0][0] = v1.x; matrix[0][1] = v2.x; matrix[0][2] = v3.x;
	matrix[1][0] = v1.y; matrix[1][1] = v2.y; matrix[1][2] = v3.y;
	matrix[2][0] = v1.z; matrix[2][1] = v2.z; matrix[2][2] = v3.z;
}

Matrix3 Matrix3::operator*(Matrix3 m2)
{
	if (n != m2.m) {
		return *this;
	}
	else {

		Matrix3 newMat = Matrix3();
		float math = 0.0f;
		for (int r = 0; r < m; r++) {
			for (int c = 0; c < m2.n; c++) {
				for (int i = 0; i < n; i++) {
					math += matrix[r][i] * m2.matrix[i][c];
				}
				newMat.matrix[r][c] = math;
				math = 0;
			}
		}

		return newMat;
	}
}

Vector3 Matrix3::operator*(Vector3 v3)
{
	Vector3 res = Vector3();
	res.x += v3.x * matrix[0][0];
	res.x += v3.y * matrix[0][1];
	res.x += v3.z * matrix[0][2];

	res.y += v3.x * matrix[1][0];
	res.y += v3.y * matrix[1][1];
	res.y += v3.z * matrix[1][2];

	res.z += v3.x * matrix[2][0];
	res.z += v3.y * matrix[2][1];
	res.z += v3.z * matrix[2][2];


	return res;
}

Matrix3 Matrix3::getTranspose()
{
	Matrix3 mat = Matrix3();

	for (int r = 0; r< m; r++) {
		for (int c = 0; c < n; c++) {
			mat.matrix[c][r] = matrix[r][c];
		}
	}
	return mat;
}

void Matrix3::transpose()
{
	Matrix3 mat = getTranspose();
	for (int r = 0; r < m; r++) {
		for (int c = 0; c < n; c++) {
			mat.matrix[r][c] = matrix[r][c];
		}
	}
}

float * Matrix3::operator[](const int axis)
{
	return nullptr; //DO THE UNION THING HERE TO MAKE SHIT WORK 
}


Matrix3::operator float*()
{
	float * mat = new float[9];
	mat[0] = matrix[0][0];
	mat[1] = matrix[1][0];
	mat[2] = matrix[2][0];
	mat[3] = matrix[0][1];
	mat[4] = matrix[1][1];
	mat[5] = matrix[2][1];
	mat[6] = matrix[0][2];
	mat[7] = matrix[1][2];
	mat[8] = matrix[2][2];
	return mat;
}

void Matrix3::stdPrintMat()
{
	std::cout << "(" << m << "," << n << ")" << std::endl;
	for (int r = 0; r < m; r++) {
		for (int c = 0; c < n; c++) {
			std::cout << matrix[r][c] << " ";
		}
		std::cout << std::endl;
	}
}

void Matrix3::setRotateX(float angle)
{
	float degToRad = M_PI / 180.0f; //
	Matrix3 rotateMatX = Matrix3(1,0,0, 0, cos(angle*degToRad), sin(angle*degToRad), 0, -sin(angle*degToRad), cos(angle*degToRad));
	(*this) = (*this) * rotateMatX;
}


void Matrix3::setRotateY(float angle)
{
	float degToRad = M_PI / 180.0f; //
	Matrix3 rotateMatY = Matrix3(cos(angle*degToRad), 0, sin(angle*degToRad), 0, 1, 0, -sin(angle*degToRad), 0, cos(angle*degToRad));
	(*this) = (*this) * rotateMatY;
}

void Matrix3::setRotateZ(float angle)
{
	float degToRad = M_PI / 180.0f; //
	Matrix3 rotateMatZ = Matrix3(cos(angle*degToRad), sin(angle*degToRad), 0, -sin(angle*degToRad), cos(angle*degToRad), 0, 0, 0, 1);
	(*this) = (*this) * rotateMatZ;
}

void Matrix3::setRotate(float x, float y, float z)
{
	setRotateX(x);
	setRotateY(y);
	setRotateZ(z);
}

void Matrix3::translate(Vector3 v) {
	v.z = 1;
	Matrix3 transMat = Matrix3(Vector3(1,0,0),Vector3(0,1,0),v);
	(*this) = (*this) * transMat;
}




