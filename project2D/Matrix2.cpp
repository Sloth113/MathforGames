#include "Matrix2.h"


Matrix2::Matrix2()
{
	m = 2; n = 2;


	matrix[0][0] = 1.0f; matrix[0][1] = 0.0f;
	matrix[1][0] = 0.0f; matrix[1][1] = 1.0f;


}

Matrix2::Matrix2(float Xx, float Xy, float Yx, float Yy)
{
	m = 2; n = 2;
	matrix[0][0] = Xx; matrix[0][1] = Yx;
	matrix[1][0] = Xy; matrix[1][1] = Yy;

}

Matrix2::Matrix2(Vector2 v1, Vector2 v2)
{
	matrix[0][0] = v1.x; matrix[1][0] = v2.x;
	matrix[0][1] = v1.y; matrix[1][1] = v2.y;
}



Matrix2 Matrix2::operator*(Matrix2 m2)
{
	if (n != m2.m) {
		return *this;
	}
	else {

		Matrix2 newMat = Matrix2();
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

Vector2 Matrix2::operator*(Vector2 v2)
{
	Vector2 res = Vector2(matrix[0][0] * v2.x + matrix[1][0] * v2.x, matrix[0][1] * v2.y + matrix[1][1] * v2.y);
	
	return res;
}


Matrix2 Matrix2::getTranspose()
{
	Matrix2 mat = Matrix2();

	for (int r = 0; r< m; r++) {
		for (int c = 0; c < n; c++) {
			mat.matrix[c][r] = matrix[r][c];
		}
	}
	return mat;
}

void Matrix2::transpose()
{
	Matrix2 mat = getTranspose();
	//Copy values
	for (int r = 0; r < m; r++) {
		for (int c = 0; c < n; c++) {
			mat.matrix[r][c] = matrix[r][c];
		}
	}
}

Vector2 & Matrix2::operator[](const int axis)
{
	if (axis <= 0) return Vector2(matrix[0][0],matrix[1][0]);
	if (axis >= 1) return Vector2(matrix[0][1], matrix[1][1]);
}




Matrix2::operator float*()
{
	float * mat = new float[4];
	mat[0] = matrix[0][0];
	mat[1] = matrix[1][0];
	mat[2] = matrix[0][1];
	mat[3] = matrix[1][1];

	return mat;
}

void Matrix2::stdPrintMat()
{
	std::cout << "(" << m << "," << n << ")" << std::endl;
	for (int r = 0; r < m; r++) {
		for (int c = 0; c < n; c++) {
			std::cout << matrix[r][c] << " ";
		}
		std::cout << std::endl;
	}
}

void Matrix2::setRotate(float angle)
{
	
	float degToRad = M_PI/180.0f; //
	Matrix2 rotateMat = Matrix2(cos(angle*degToRad), sin(angle*degToRad), -sin(angle*degToRad), cos(angle*degToRad));
	(*this) = (*this) * rotateMat;
}




