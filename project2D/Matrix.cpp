#include "Matrix.h"

Matrix::Matrix()
{
	m = 3; n = 3;
	matrix = new float*[3];
	matrix[0] = new float[3];
	matrix[1] = new float[3];
	matrix[2] = new float[3];

	matrix[0][0] = 1.0f; matrix[0][1] = 0.0f; matrix[0][2] = 0.0f;
	matrix[1][0] = 0.0f; matrix[1][1] = 1.0f; matrix[1][2] = 0.0f;
	matrix[2][0] = 0.0f; matrix[2][1] = 0.0f; matrix[2][2] = 1.0f;

}

Matrix::Matrix(float Xx, float Xy, float Yx, float Yy)
{
	m = 2; n = 2;
	matrix = new float*[m];
	matrix[0] = new float[n];
	matrix[1] = new float[n];
	

	matrix[0][0] = Xx; matrix[0][1] = Yx;
	matrix[1][0] = Xy; matrix[1][1] = Yy;

}

Matrix::Matrix(float Xx, float Xy, float Xz, float Yx, float Yy, float Yz, float Zx, float Zy, float Zz)
{
	m = 3; n = 3;
	matrix = new float*[m];
	matrix[0] = new float[n];
	matrix[1] = new float[n];
	matrix[2] = new float[n];

	matrix[0][0] = Xx; matrix[0][1] = Yx; matrix[0][2] = Zx;
	matrix[1][0] = Xy; matrix[1][1] = Yy; matrix[1][2] = Zy;
	matrix[2][0] = Xz; matrix[2][1] = Yz; matrix[2][2] = Zz;
}

Matrix::Matrix(int rows, int cols)
{
	m = rows;
	n = cols;

	matrix = new float*[m];
	for (int i = 0; i < m; i++) {
		matrix[i] = new float[n];
	}

}

Matrix::Matrix(Vector2 v2)
{
	m = 2;
	n = 1;
	matrix = new float*[m];
	matrix[0] = new float[n];
	matrix[1] = new float[n];

	matrix[0][0] = v2.x;
	matrix[0][1] = v2.y;


}

Matrix::Matrix(Vector3 v3)
{
	m = 3;
	n = 1;
	matrix = new float*[m];
	matrix[0] = new float[n];
	matrix[1] = new float[n];
	matrix[2] = new float[n];

	matrix[0][0] = v3.x;
	matrix[1][0] = v3.y;
	matrix[2][0] = v3.z;

}

Matrix::Matrix(Vector2 v1, Vector2 v2)
{

	m = 2; n = 2;
	matrix = new float*[m];
	matrix[0] = new float[n];
	matrix[1] = new float[n];


	matrix[0][0] = v1.x; matrix[1][0] = v2.x;
	matrix[0][1] = v1.y; matrix[1][1] = v2.y;
}

Matrix::Matrix(Vector3 v1, Vector3 v2, Vector3 v3)
{
	m = 3; n = 3;
	matrix = new float*[m];
	matrix[0] = new float[n];
	matrix[1] = new float[n];
	matrix[2] = new float[n];

	matrix[0][0] = v1.x; matrix[0][1] = v2.x; matrix[0][2] = v3.x;
	matrix[1][0] = v1.y; matrix[1][1] = v2.y; matrix[1][2] = v3.y;
	matrix[2][0] = v1.z; matrix[2][1] = v2.z; matrix[2][2] = v3.z;
}

Matrix::Matrix(const Matrix & mat)
{
	matrix = new  float*[mat.m];
	for (int i = 0; i < mat.m; i++) {
		matrix[i] = new float[mat.n];
	}
	matrix = mat.matrix;
	m = mat.m;
	n = mat.n;
}

//Matrix::~Matrix()
//{
//	if (matrix != nullptr) {
//		for (int i = 0; i < m; i++) {
//			//delete [] matrix[i];
//		}
//		//delete [] matrix;
//	}
//	//matrix = nullptr;
//}

Matrix Matrix::operator*(Matrix m2)
{
	if (n != m2.m){
		return *this;
	}
	else {

		Matrix newMat = Matrix(m,m2.n);
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

Matrix Matrix::operator*(Vector2 v2)
{
	Matrix tmp = Matrix(v2);
	Matrix res = (*this) * tmp;
	return res;
}

Matrix Matrix::operator*(Vector3 v3)
{
	Matrix tmp = Matrix(v3);
	Matrix res = (*this) * tmp;
	return res;
}

Matrix Matrix::getTranspose()
{
	Matrix mat = Matrix(n, m);
	
	for (int r = 0; r< m; r++) {
		for (int c = 0; c < n; c++) {
			mat.matrix[c][r] = matrix[r][c];
		}
	}
	return mat;
}

void Matrix::transpose()
{
	Matrix mat = Matrix(n, m);
	for (int r = 0; r < m; r++) {
		for (int c = 0; c < n; c++) {
			mat.matrix[c][r] = matrix[r][c];
		}
	}
	matrix = mat.matrix;
}




void Matrix::stdPrintMat()
{
	std::cout << "(" << m <<"," <<n << ")" << std::endl;
	for (int r = 0; r < m; r++) {
		for (int c = 0; c < n; c++) {
			std::cout << matrix[r][c] << " ";
		}
		std::cout << std::endl;
	}
}




