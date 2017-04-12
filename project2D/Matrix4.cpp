#include "Matrix4.h"

Matrix4::Matrix4()
{
	m = 4, n = 4;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			matrix[m][n] = 0;
	}
}

Matrix4::Matrix4(float Xx, float Xy, float Xz, float Xw, float Yx, float Yy, float Yz, float Yw, float Zx, float Zy, float Zz, float Zw, float Wx, float Wy, float Wz, float Ww)
{
	m = 4; n = 4;
	matrix[0][0] = Xx; matrix[0][1] = Yx; matrix[0][2] = Zx; matrix[0][3] = Wx;
	matrix[1][0] = Xy; matrix[1][1] = Yy; matrix[1][2] = Zy; matrix[1][3] = Wy;
	matrix[2][0] = Xz; matrix[2][1] = Yz; matrix[2][2] = Zz; matrix[2][3] = Wz;
	matrix[3][0] = Xw; matrix[3][1] = Yw; matrix[3][2] = Zw; matrix[3][3] = Ww;
}

Matrix4::Matrix4(float[4][4])
{
}

Matrix4::Matrix4(Matrix3 mat )
{
	m = 4; n = 4;
	matrix[0][0] = mat.matrix[0][0];	matrix[0][1] =mat.matrix[0][1];	matrix[0][2] =mat.matrix[0][2];	matrix[0][3] = 0;
	matrix[1][0] = mat.matrix[1][0];	matrix[1][1] =mat.matrix[1][1];	matrix[1][2] =mat.matrix[1][2];	matrix[1][3] = 0;
	matrix[2][0] = mat.matrix[2][0];	matrix[2][1] =mat.matrix[2][1];	matrix[2][2] =mat.matrix[2][2];	matrix[2][3] = 0;
	matrix[3][0] = 0;					matrix[3][1] = 0;				matrix[3][2] = 0;				matrix[3][3] = 1;
}

Matrix4::Matrix4(Vector4 v1, Vector4 v2, Vector4 v3, Vector4 v4)
{
	m = 4; n = 4;

	matrix[0][0] = v1.x; matrix[0][1] = v2.x; matrix[0][2] = v3.x; matrix[0][3] = v4.x;
	matrix[1][0] = v1.y; matrix[1][1] = v2.y; matrix[1][2] = v3.y; matrix[1][3] = v4.y;
	matrix[2][0] = v1.z; matrix[2][1] = v2.z; matrix[2][2] = v3.z; matrix[2][3] = v4.z;
	matrix[3][0] = v1.w; matrix[3][1] = v2.w; matrix[3][2] = v3.w; matrix[3][3] = v4.w;


}

Matrix4::Matrix4(Vector3 v1, Vector3 v2, Vector3 v3, Vector3 v4)
{
	m = 4; n = 4;

	matrix[0][0] = v1.x; matrix[0][1] = v2.x; matrix[0][2] = v3.x; matrix[0][3] = v4.x;
	matrix[1][0] = v1.y; matrix[1][1] = v2.y; matrix[1][2] = v3.y; matrix[1][3] = v4.y;
	matrix[2][0] = v1.z; matrix[2][1] = v2.z; matrix[2][2] = v3.z; matrix[2][3] = v4.z;

	matrix[3][0] = 0; matrix[3][1] = 0; matrix[3][2] = 0; matrix[3][3] = 0;
}

Matrix4 Matrix4::operator*(Matrix4 m4)
{
	if (n != m4.m) {
		return *this;
	}
	else {

		Matrix4 newMat = Matrix4();
		float math = 0.0f;
		for (int r = 0; r < m; r++) {
			for (int c = 0; c < m4.n; c++) {
				for (int i = 0; i < n; i++) {
					math += matrix[r][i] * m4.matrix[i][c];
				}
				newMat.matrix[r][c] = math;
				math = 0;
			}
		}

		return newMat;
	}

}
Matrix4 Matrix4::operator*(Matrix3 m3)
{
	n = 3; m = 3;
	if (n != m3.m) {
		return *this;
	}
	else {

		Matrix4 newMat = Matrix4();
		float math = 0.0f;
		for (int r = 0; r < m; r++) {
			for (int c = 0; c < m3.n; c++) {
				for (int i = 0; i < n; i++) {
					math += matrix[r][i] * m3.matrix[i][c];
				}
				newMat.matrix[r][c] = math;
				math = 0;
			}
		}
		m = 4; n = 4;


		//newMat[3] = (*this)[3]; should work
		//last col (pos) 
		newMat.matrix[0][3] = matrix[0][3];
		newMat.matrix[1][3] = matrix[0][3];
		newMat.matrix[2][3] = matrix[0][3];
		newMat.matrix[3][3] = matrix[0][3];
		//Bottom row
		newMat.matrix[3][0] = 0; newMat.matrix[3][1] = 0; newMat.matrix[3][2] = 0;


		return newMat;
	}
	//ignore last col and row (positions things)
}

Vector4 Matrix4::operator*(Vector4)
{
	return Vector4();
}

Matrix4 Matrix4::getTranspose()
{
	Matrix4 mat = Matrix4();

	for (int r = 0; r< m; r++) {
		for (int c = 0; c < n; c++) {
			mat.matrix[c][r] = matrix[r][c];
		}
	}
	return mat;
}

void Matrix4::transpose()
{
	Matrix4 mat = getTranspose();
	for (int r = 0; r < m; r++) {
		for (int c = 0; c < n; c++) {
			mat.matrix[r][c] = matrix[r][c];
		}
	}
}

Vector4 * Matrix4::operator[](const int axis)
{
	return nullptr;
}

Matrix4::operator float*()
{
	float * mat = new float[9];
	mat[0] = matrix[0][0];
	mat[1] = matrix[1][0];
	mat[2] = matrix[2][0];
	mat[3] = matrix[3][0];
	mat[4] = matrix[0][1];
	mat[5] = matrix[1][1];
	mat[6] = matrix[2][1];
	mat[7] = matrix[3][1];
	mat[8] = matrix[0][2];
	mat[9] = matrix[1][2];
	mat[10] = matrix[2][2];
	mat[11] = matrix[3][2];
	mat[12] = matrix[0][3];
	mat[13] = matrix[1][3];
	mat[14] = matrix[2][3];
	mat[15] = matrix[3][3];

	return mat;
}

void Matrix4::stdPrintMat()
{
	std::cout << "(" << m << "," << n << ")" << std::endl;
	for (int r = 0; r < m; r++) {
		for (int c = 0; c < n; c++) {
			std::cout << matrix[r][c] << " ";
		}
		std::cout << std::endl;
	}
}

void Matrix4::setRotateX(float angle)
{
	float degToRad = M_PI / 180.0f; //
	Matrix3 rotateMatX = Matrix3(1, 0, 0, 0, cos(angle*degToRad), sin(angle*degToRad), 0, -sin(angle*degToRad), cos(angle*degToRad));
	(*this) = (*this) * rotateMatX;
}

void Matrix4::setRotateY(float angle)
{
	float degToRad = M_PI / 180.0f; //
	Matrix3 rotateMatY = Matrix3(cos(angle*degToRad), 0, -sin(angle*degToRad), 0, 1, 0, sin(angle*degToRad), 0, cos(angle*degToRad));
	(*this) = (*this) * rotateMatY;
}

void Matrix4::setRotateZ(float angle)
{
	float degToRad = M_PI / 180.0f; //
	Matrix3 rotateMatZ = Matrix3(cos(angle*degToRad), sin(angle*degToRad), 0, -sin(angle*degToRad), cos(angle*degToRad), 0, 0, 0, 1);
	(*this) = (*this) * rotateMatZ;
}

void Matrix4::setRotate(float x, float y, float z)
{
	setRotateX(x);
	setRotateY(y);
	setRotateZ(z);
}

void Matrix4::translate(Vector4 v)
{
	v.w = 1;
	Matrix4 transMat = Matrix4(Vector4(1, 0, 0,0), Vector4(0, 1, 0,0), Vector4(0,0,1,0), v);
	(*this) = (*this) * transMat;
}

void Matrix4::translate(Vector3 v)
{
	Matrix4 transMat = Matrix4(Vector4(1, 0, 0, 0), Vector4(0, 1, 0, 0), Vector4(0, 0, 1, 0), Vector4(v.x,v.y,v.z,1));
	(*this) = (*this) * transMat;
}

