/*
		MPEI Algebraic Abstractions Library,
		2007-2011,
		Moscow Power Engineering Institute

        This file contains definitions and implementations of the following classes:

*/
#ifndef __ELLIPTICCURVES_H__
#define __ELLIPTICCURVES_H__

#include "Integer.h"
#include <string>
#include <stdio.h>


namespace AAL
{
	class EllipticCurve
	{
	private:
		Integer *_module;
		Integer *_a;
		Integer *_b;

	//������������
	public:
		//default: y=x^3+x+b mod(5)
		EllipticCurve();
		EllipticCurve(Integer &module, Integer &J);
		//4a^3+27b^2 != 0 mod(module)
		EllipticCurve(Integer &module, Integer &a, Integer &b);
		EllipticCurve(const EllipticCurve &eCurve);
		~EllipticCurve();

	//������ ���������
	private:
		bool isSmooth(Integer &module, Integer &a, Integer &b) const;
	public:
		Integer& getModule() const;
		Integer getInvariant() const;
		Integer& getA() const;
		Integer& getB() const;
		Integer& setModule(Integer &module);
		Integer& setA(Integer &a);
		Integer& setB(Integer &b);
                Integer getOrder();
		EllipticCurve& setCurve(Integer &module, Integer &J);
		EllipticCurve& setCurve(Integer &module);

	//������� ��������
	public:
		EllipticCurve& operator=(const EllipticCurve &eCurve);

	//�������� ���������
	public:
		friend bool operator==(const EllipticCurve &eCurve1, const EllipticCurve &eCurve2);
		friend bool operator!=(const EllipticCurve &eCurve1, const EllipticCurve &eCurve2);
	//�������������� ����� � ������
	public:
		bool inGroup(Integer &x, Integer &y) const;
	};

	class EllipticPoint
	{
	private:
		EllipticCurve *_curve;
		Integer *_x;
		Integer *_y;
		bool _infinite;

	//������������
	public:
		EllipticPoint();
		EllipticPoint(const EllipticCurve &eCurve);
		EllipticPoint(const EllipticPoint &ePoint);
		~EllipticPoint();

	//������ ���������
	public:
		EllipticCurve& getCurve();
		Integer& getX();
		Integer& getY();
		EllipticCurve& setCurve(EllipticCurve &eCurve);
		EllipticPoint& setXY(Integer &x, Integer &y);
		bool isInfinite() const;
		EllipticPoint& setInfinite(bool infinite);

	//������� ��������
	public:
		EllipticPoint& operator=(const EllipticPoint &ePoint);

	//�������� ���������
	public:
		friend bool operator==(const EllipticPoint &ePoint1, const EllipticPoint &ePoint2);
		friend bool operator!=(const EllipticPoint &ePoint1, const EllipticPoint &ePoint2);

        //�������� ������ ��������������� ����� (-P)
                EllipticPoint& Negate();
		EllipticPoint& Negate(EllipticPoint& ePoint);
	//�������� ��������
	public:
		friend EllipticPoint operator+(EllipticPoint &ePoint1, EllipticPoint &ePoint2);
		EllipticPoint& operator+=(EllipticPoint &ePoint1);
		EllipticPoint& Add(EllipticPoint &ePoint1, EllipticPoint &ePoint2);

	//�������� ��������
	public:
		EllipticPoint& Double();
		EllipticPoint& Double(EllipticPoint &e);

	//�������� ��������� �� ���������
	public:
		friend EllipticPoint operator*(const EllipticPoint &ePoint, const Integer &i);
		friend EllipticPoint operator*(const Integer &i, const EllipticPoint &ePoint);
		EllipticPoint& operator*=(Integer &i);
		EllipticPoint& Mul(Integer &i, EllipticPoint &ePoint);
		EllipticPoint& Mul(EllipticPoint &ePoint, Integer &i);

	//��������� �����
		EllipticPoint& Generate();
	};
}

#endif
