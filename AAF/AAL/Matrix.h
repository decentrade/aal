/*
		MPEI Algebraic Abstractions Library,
		2007-2011,
		Moscow Power Engineering Institute

        This file contains definitions and implementations of the following classes:

*/
//---------------------------------------------------------------------------

#ifndef MatrixH
#define MatrixH
//---------------------------------------------------------------------------
#include <vector>
#include <string>
#include <math.h>
#include "Polynom.h"
#include "Converter.h"
//---------------------------------------------------------------------------
using std::vector;
using std::string;

namespace AAL
{
  // �������������� ����
  const int P = 2; 

  class Matrix
  {
    public:
      // ������ "����������" - �� �������, �� ��������
      enum CodingSystem {ON_LINE = 1, ON_COLUMN = 2};
      // ��� ����������� �������
      // �� ���������, ������-������, �����-�������
      enum TrianType {NONE = 0, RIGHT = 1, LEFT = 2};
    private:
      // ����� ����� - 8 ��� (��� uchar)
      static const int Len_Word = 8;
      // ������ "����������" - �� �������, �� ��������
      CodingSystem  CodeWord;
      // ��������� �� ������� � ������������ ���� ��� ��� � � ������
      TrianType IsTrian;
      // ����������� �� �������
      // ��������� {false}, ����������� {true}
      // ������ ������������, ��� ������� �����������
      bool IsNonSign;
      // �������� � ����� � �������� �������
      uint ColCount, RowCount;
      // �������, ������������ ����� ������ ���������
      vector<Polynom*> plMatrix;
    private:
      // ������ ��� ����������� �������������
      //friend void createUnitaryMatrixLeft(uint aRowCount, uint aColCount, CodingSystem aCodeWord, Matrix& A);
      void createUnitaryMatrixLeft(uint aRowCount, uint aColCount, CodingSystem aCodeWord, Matrix& A);
      //friend void createUnitaryMatrixRight(int aRowCount, int aColCount, CodingSystem aCodeWord, Matrix& A);
      void createUnitaryMatrixRight(uint aRowCount, uint aColCount, CodingSystem aCodeWord, Matrix& A);
      void setTrianType(TrianType aIsTrian);
      void setIsNonSign(bool bIsNonSign);
      bool getIsNonSign() const;

      void setSizeMatrixByte(uint nColCount, uint nRowCount);
      void getSizeMatrixByte(uint &nColCount, uint &nRowCount);

    public:
      // ������������/�����������
      Matrix();
      Matrix(const Matrix& matrix);
      Matrix(CodingSystem aCodeWord, uint aColCount, uint aRowCount);
      Matrix(CodingSystem aCodeWord, uint aColCount, uint aRowCount, bool aValue);
      Matrix(CodingSystem aCodeWord, uint aColCount, uint aRowCount, vector<Polynom*> aNewMatrix);
      Matrix(CodingSystem aCodeWord, uint aColCount, uint aRowCount, vector<string> aNewMatrix);
      Matrix(vector<Polynom*> aNewMatrix);
      Matrix(vector<string> aNewMatrix);
     // Matrix(CodingSystem aCodeWord, uint aColCount, uint aRowCount, bool aValue);

      ~Matrix();

      // accessors/mutators
      void setSize(uint aSize);
      uint getSize() const;
      void setElemMatrix(uint i, Polynom& newElem);
      Polynom& getElemMatrix(int i) const;
      void setCoding(CodingSystem aCodeWord);
      CodingSystem getCoding() const;
      TrianType getTrianType() const;
      void setSizeMatrixBits(uint nColCount, uint nRowCount);
      void getSizeMatrixBits(uint &nColCount, uint &nRowCount) const;
      bool getBit(uint nRowPosition, uint nColPosition) const;
      void setBit(uint nRowPosition, uint nColPosition, bool bValue = true);
      uint getColCount() const;
      uint getRowCount() const;
      uint getSizeWordInBits() const;

      // ������� ��������
      Matrix& operator= (const Matrix& matrix);

      // �������� ���������
      friend bool operator==(const Matrix& a, const Matrix& b);
      friend bool operator!=(const Matrix& a, const Matrix& b);
      friend bool equalityParams(const Matrix& a, const Matrix& b);

      // ��������� �������
      bool isZero() const;
      //bool isOne() const;
      uint getColCountMatrixByte() const;
      uint getRowCountMatrixByte() const;
      vector<string> ToString();
	  std::string i_to_str(uint x) const;
      string ToStringLine();
      string ToStringNotNullBits();
      // ��������� ������� ��� ���������� �������
      friend void generateMatrix(const Polynom& plBegin, int nPow, Matrix& A);
      //void generateMatrix(const Polynom& plBegin, int nPow, Matrix& A);


      //��������� ������  � ��������
      // ����� ����������
      Matrix& conversionMatrix();
      // ���������� � ������������ ����
      Matrix& gausRightTrian();
      Matrix& gausLeftTrianBits();
      Matrix& gausRightTrianBits();
      Matrix& konovalcevRightTrian();
      Matrix& konovalcevLeftTrianBits();
      Matrix& konovalcevRightTrianBits();
      // �������� �� ���������������
      bool nonsignMatrix();
      // ���������� � ������������� ����
      Matrix& gausRightDiag();
      Matrix& gausLeftDiagBits();
      Matrix& gausRightDiagBits();
      Matrix& diagWithoutNonsign();
      // ��������� �������
      Matrix& reverseLeftBits();
      Matrix& reverseRight();

    // ������� ����
    public:
      Matrix & Transpose();
      Polynom SolveLinearEquationSystem(const Matrix & A, const Polynom & right);
      Matrix& gausRightTrianForEquation(Polynom & right);
      Matrix& gausRightDiagForEquation(Polynom & right);
    public:
      std::string ToString() const;// TODO: �����������

      // �������� � ��������� � ���������
      friend Polynom mulVecToMatrix(const Polynom& plA, const Matrix& mtB);
      friend Polynom mulMatrixToVec(const Polynom& plA, const Matrix& mtB);
      Matrix& mul(const Matrix& mtA, const Matrix& mtB);
  };
};
//---------------------------------------------------------------------------
#endif
