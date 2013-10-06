/*
		MPEI Algebraic Abstractions Library,
		2007-2011,
		Moscow Power Engineering Institute

        This file contains definitions and implementations of the following classes:

*/
#ifndef __ELLIPTICCURVESGF2_H__
#define __ELLIPTICCURVESGF2_H__

#include "Polynom.h"
#include "PolynomGF2_m_4.h"
#include "PolynomGF2_mY_7.h"

namespace AAL
{
        class Matrix;
        // ����������� ������� ����� ������������� ������ ��� ����� GF(2^n)
        class    EllipticCurveGF2
        {
        protected:
        	Polynom *_module;
        //����������� ����������
        public:
                virtual ~EllipticCurveGF2() = 0;
        //������ ���������
	public:
		Polynom& getModule() const;
                virtual Polynom& setModule(const Polynom &module) = 0;
                virtual bool isSuperSingular() const = 0;
                virtual bool isNonSuperSingular() const = 0;
        //�������� ���������
        public:
                virtual bool equals(const EllipticCurveGF2 &eCurve) const = 0;
                friend bool operator==(const EllipticCurveGF2 &eCurve1, const EllipticCurveGF2 &eCurve2);
		friend bool operator!=(const EllipticCurveGF2 &eCurve1, const EllipticCurveGF2 &eCurve2);
        //�������������� ����� � ������
        public:
                virtual bool inGroup(Polynom &x, Polynom &y) const = 0;
        //���������� ������ ����� ���������
        public:
                virtual Polynom rightSide(Polynom &x) const = 0;
        // �������� �� ������������� Y ��� ������� X
        public:
                virtual bool hasY(Polynom &x) const = 0;
        //������� ��������
        private:
                EllipticCurveGF2& operator=(const EllipticCurveGF2 &eCurve);// �������� �������������
        };
        // ����� "����������������" ������������� ������ ��� ����� GF(2^n)
        // ���: Y^2 + a3*Y = X^3 + a4*X + a6
        class SuperSingularEllipticCurve : public EllipticCurveGF2
	{
        private:
                Polynom *_a3;
                Polynom *_a4;
                Polynom *_a6;
	//������������
	public:
		//default: Y^2 + Y = X^3 + X + 1 (mod m(x) = 1+x+x^3)
		SuperSingularEllipticCurve();
		SuperSingularEllipticCurve(Polynom &module, Polynom &a3, Polynom &a4, Polynom &a6);
		SuperSingularEllipticCurve(const SuperSingularEllipticCurve &eCurve);
		~SuperSingularEllipticCurve();
	//������ ���������
	public:
                Polynom& setModule(const Polynom &module);
		Polynom& getA3() const;
		Polynom& getA4() const;
		Polynom& getA6() const;
		Polynom& setA3(Polynom &a3);
		Polynom& setA4(Polynom &a4);
		Polynom& setA6(Polynom &a6);
                bool isSuperSingular() const;
                bool isNonSuperSingular() const;
                Integer& getOrd(int step);
	//������� ��������
	public:
		SuperSingularEllipticCurve& operator=(const SuperSingularEllipticCurve &eCurve);
	//�������� ���������
	public:
                bool equals(const EllipticCurveGF2 &eCurve) const;
	//�������������� ����� � ������
	public:
		bool inGroup(Polynom &x, Polynom &y) const;
        //���������� ������ ����� ��������� X^3 + a4*X + a6
        public:
                Polynom rightSide(Polynom &x) const;
        // �������� �� ������������� Y ��� ������� X
        public:
                bool hasY(Polynom &x) const;
        };

        // ����������� ������� ����� ����� ������������� ������ ��� ����� GF(2^n)
        class EllipticPointGF2
        {
        protected:
                EllipticCurveGF2 *_curve;
                bool _infinite;
                Polynom *_x;
		Polynom *_y;
        // ����������� ����������
        public:
                virtual ~EllipticPointGF2() = 0;
        //������ ���������
        public:
		EllipticCurveGF2& getCurve();
                virtual EllipticCurveGF2& setCurve(EllipticCurveGF2& curve) = 0;
                Polynom& getX();
		Polynom& getY();
                EllipticPointGF2& setXY(Polynom &x, Polynom &y);
                bool isInfinite() const;
		EllipticPointGF2& setInfinite(bool infinite);

        public:
                friend bool operator==(const EllipticPointGF2 &ePoint1, const EllipticPointGF2 &ePoint2);
		friend bool operator!=(const EllipticPointGF2 &ePoint1, const EllipticPointGF2 &ePoint2);
        //�������� ������ ��������������� ����� (-P)
        public:
                virtual EllipticPointGF2& Negate();
                virtual EllipticPointGF2& Negate(EllipticPointGF2 &ePoint) = 0;
        //�������� ��������
        public:
                //friend EllipticPointGF2 operator+(EllipticPointGF2 &ePoint1, EllipticPointGF2 &ePoint2);
		EllipticPointGF2& operator+=(EllipticPointGF2 &ePoint);
                virtual EllipticPointGF2& Add(EllipticPointGF2 &ePoint1, EllipticPointGF2 &ePoint2) = 0;

        //�������� ��������
	public:
		virtual EllipticPointGF2& Double();
		virtual EllipticPointGF2& Double(EllipticPointGF2 &ePoint) = 0;

	//�������� ��������� �� ���������
	public:
		//friend EllipticPoint operator*(const EllipticPoint &ePoint, const Integer &i);
		//friend EllipticPoint operator*(const Integer &i, const EllipticPoint &ePoint);
		EllipticPointGF2& operator*=(Integer &i);
		//EllipticPoint& Mul(Integer &i, EllipticPoint &ePoint);
		virtual EllipticPointGF2& Mul(EllipticPointGF2 &ePoint, const Integer &i) = 0;
        // ��������� �����
        public:
                EllipticPointGF2& Generate();
        // ��������� ����� � ��������� ������
        public:
                EllipticPointGF2& WrappingGenerate(const Polynom & xforwrap);
        protected:
                virtual EllipticPointGF2& GenerateImpl(const Polynom * xforwrap = NULL) = 0;
        protected:
                Polynom findYOddCase(const Polynom & right); // ������� ��������� Y^2 + Y = right, n = 2k+1
                Polynom findYEvenCase(const Polynom & right); // ������� ��������� Y^2 + Y = right, n = 2k
                Matrix createGenerationMatrix(); // �������� ������� ���� ��� n = 2k
        public:
                friend class SuperSingularEllipticPoint;
                friend class NonSuperSingularEllipticPoint;
        private:
                EllipticPointGF2& operator=(const EllipticPointGF2 &ePoint);// �������� �������������
        public:
                AAL::PolynomGF2_m_4& DLK(EllipticPointGF2 &ePoint1,EllipticPointGF2 &ePoint2,AAL::PolynomGF2_m_4 &t,int n,AAL::PolynomGF2_m_4 &b,Polynom &mod);
        public:
                AAL::PolynomGF2_m_4& findRo(Polynom &module, AAL::PolynomGF2_m_4 &b );


        };
//***********************************************************************************************
        // ����� ����� "����������������" ������������� ������ ��� ����� GF(2^n)
        class SuperSingularEllipticPoint : public EllipticPointGF2
	{
	//������������
	public:
		SuperSingularEllipticPoint();
		SuperSingularEllipticPoint(const SuperSingularEllipticCurve &eCurve);
		SuperSingularEllipticPoint(const SuperSingularEllipticPoint &ePoint);
		~SuperSingularEllipticPoint();
        //������ ���������
        public:
		SuperSingularEllipticCurve& setCurve(EllipticCurveGF2 &eCurve);

	//������� ��������
	public:
		SuperSingularEllipticPoint& operator=(const SuperSingularEllipticPoint &ePoint);
        //�������� ������ ��������������� ����� (-P)
        public:
                EllipticPointGF2& Negate(); // ����� ��������������, ����� ����� ���������
                EllipticPointGF2& Negate(EllipticPointGF2 &ePoint);
        //�������� ��������
        public:
                EllipticPointGF2& Add(EllipticPointGF2 &ePoint1, EllipticPointGF2 &ePoint2);
        //�������� ��������
	public:
                EllipticPointGF2& Double();// ����� ��������������, ����� ����� ���������
                EllipticPointGF2& Double(EllipticPointGF2 &e);
        //�������� ��������� �� ���������
	public:
		EllipticPointGF2& Mul(EllipticPointGF2 &ePoint, const Integer &i);
        protected:
                SuperSingularEllipticPoint& GenerateImpl(const Polynom * xforwrap = NULL); // �������, ������� ��� ��� �������� �������� �� ���������
        };

//*******************************************************************************************************************************************************************************
        // ����� "������������������" ������������� ������ ��� ����� GF(2^n)
        // ���: Y^2 + X*Y = X^3 + a2*X^2 + a6
        class NonSuperSingularEllipticCurve : public EllipticCurveGF2
	{
        private:
                Polynom *_a2;
                Polynom *_a6;
	//������������
	public:
		//default: Y^2 + X*Y = X^3 + X^2 + 1 (mod m(x) = 1+x+x^3)
		NonSuperSingularEllipticCurve();
		NonSuperSingularEllipticCurve(Polynom &module, Polynom &a2, Polynom &a6);
		NonSuperSingularEllipticCurve(const NonSuperSingularEllipticCurve &eCurve);
		~NonSuperSingularEllipticCurve();
	//������ ���������
	public:
                Polynom& setModule(const Polynom &module);
		Polynom& getA2() const;
		Polynom& getA6() const;
		Polynom& setA2(Polynom &a2);
		Polynom& setA6(Polynom &a6);
        bool isSuperSingular() const;
        bool isNonSuperSingular() const;
        Integer getOrder() const;
	//������� ��������
	public:
		NonSuperSingularEllipticCurve& operator=(const NonSuperSingularEllipticCurve &eCurve);
	//�������� ���������
	public:
                bool equals(const EllipticCurveGF2 &eCurve) const;
	//�������������� ����� � ������
	public:
		bool inGroup(Polynom &x, Polynom &y) const;
        //���������� ������ ����� ��������� X^3 + a2*X^2 + a6
        public:
                Polynom rightSide(Polynom &x) const;
        // �������� �� ������������� Y ��� ������� X
        public:
                bool hasY(Polynom &x) const;
        private:
                Polynom getInvertSquare(Polynom &x) const;
        public:
                friend class NonSuperSingularEllipticPoint;
        };
        // ����� ����� "������������������" ������������� ������ ��� ����� GF(2^n)
        class NonSuperSingularEllipticPoint : public EllipticPointGF2
	{
        	//������������
	public:
		NonSuperSingularEllipticPoint();
		NonSuperSingularEllipticPoint(const NonSuperSingularEllipticCurve &eCurve);
		NonSuperSingularEllipticPoint(const NonSuperSingularEllipticPoint &ePoint);
		~NonSuperSingularEllipticPoint();
        //������ ���������
        public:
		NonSuperSingularEllipticCurve& setCurve(EllipticCurveGF2 &eCurve);
	//������� ��������
	public:
		NonSuperSingularEllipticPoint& operator=(const NonSuperSingularEllipticPoint &ePoint);
        //�������� ������ ��������������� ����� (-P)
        public:
                EllipticPointGF2& Negate(); // ����� ��������������, ����� ����� ��������
                EllipticPointGF2& Negate(EllipticPointGF2 &ePoint);
        //�������� ��������
        public:
                EllipticPointGF2& Add(EllipticPointGF2 &ePoint1, EllipticPointGF2 &ePoint2);
        //�������� ��������
	public:
                EllipticPointGF2& Double();// ����� ��������������, ����� ����� ��������
                EllipticPointGF2& Double(EllipticPointGF2 &e);
        //�������� ��������� �� ���������
	public:
		EllipticPointGF2& Mul(EllipticPointGF2 &ePoint, const Integer &i);
        protected:
                NonSuperSingularEllipticPoint& GenerateImpl(const Polynom * xforwrap = NULL); // �������, ������� ��� ��� �������� �������� �� ���������
        };
}

#endif
