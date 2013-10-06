/*
		MPEI Algebraic Abstractions Library,
		2007-2011,
		Moscow Power Engineering Institute

        This file contains definitions and implementations of the following classes:

*/
#ifndef __INTEGERBINOM_H__
#define __INTEGERBINOM_H__

#include "Integer.h"
#include "Algorithms.h"
#include <vector>

namespace AAL
{
        // �����, ��������������� ��� ������������� ����������
        // � ���� a0 + a1X + X^2, ��� a0, a1 ����������� GF(p)
        class IntegerBinomModulePolynom
        {
        private:
                Integer _a0;
                Integer _a1;
                Integer _module;
        //������������
        public:
                // ��������� 1 + X^2, p = 7
                IntegerBinomModulePolynom();
                // TODO: ������� �������� �� ��������������
                IntegerBinomModulePolynom(const IntegerBinomModulePolynom & polynom);
                IntegerBinomModulePolynom(const Integer& a0, const Integer& a1, const Integer& module);
                ~IntegerBinomModulePolynom();
        //�������������� � ���������� �� �����
	public:
		std::string ToString() const;

        //������ ���������
        public:
                const Integer& getA0() const;
                const Integer& getA1() const;
                void setA0A1(const Integer& a0, const Integer& a1);
                const Integer& getModule() const;
                void setModule(const Integer& module);
        //������� ��������
	public:
		IntegerBinomModulePolynom& operator= (const IntegerBinomModulePolynom& polynom);
	//�������� ���������
	public:
                friend bool operator==(const IntegerBinomModulePolynom& a, const IntegerBinomModulePolynom& b);
		friend bool operator!=(const IntegerBinomModulePolynom& a, const IntegerBinomModulePolynom& b);
        private:
                bool isIrreducible() const;
        };

        // �����, ��������������� ��� ������������� ��������� GF(p^2)
        // � ���� a + bX

        class IntegerBinom
        {
        private:
                Integer _a;
                Integer _b;
                IntegerBinomModulePolynom _modulePolynom;
        //������������
        public:
                // (0,0) �� ������ 1 + X^2, p = 7
                IntegerBinom();
                IntegerBinom(const IntegerBinom & binom);
                IntegerBinom(const Integer& a, const Integer& b, const IntegerBinomModulePolynom& modulePolynom);
                ~IntegerBinom();
        //�������������� � ���������� �� �����
	public:
		std::string ToString() const;
        //������ ���������
        public:
                bool isGenerative(std::vector<DecompositionMember>& mulGroupOrdDecomposition) const;
                bool isZero() const;
                bool isOne() const;
                void setZero();
                void setOne();
                const Integer& getA() const;
                void setA(const Integer & a);
                const Integer& getB() const;
                void setB(const Integer & b);
                const IntegerBinomModulePolynom& getModulePolynom() const;
                void setModulePolynom(const IntegerBinomModulePolynom& modulePolynom);
                const Integer& getModule() const;
                Integer getMulGroupOrder() const;
        //������� ��������
	public:
		IntegerBinom& operator= (const IntegerBinom& binom);
	//�������� ���������
	public:
                friend bool operator==(const IntegerBinom& a, const IntegerBinom& b);
		friend bool operator!=(const IntegerBinom& a, const IntegerBinom& b);
        //�������� ��������
	public:
		friend IntegerBinom operator+(const IntegerBinom &a, const IntegerBinom &b);
		IntegerBinom& operator+=(IntegerBinom & binom);
		IntegerBinom& Add(IntegerBinom &a, IntegerBinom &b);
        //�������� ���������
	public:
		friend IntegerBinom operator-(const IntegerBinom &a, const IntegerBinom &b);
		IntegerBinom& operator-=(IntegerBinom & binom);
		IntegerBinom& Sub(IntegerBinom &a, IntegerBinom &b);
        //�������� ������ ���������������� ��������
	public:
		IntegerBinom& Negate();
		IntegerBinom& Negate(IntegerBinom &binom);
        //�������� ���������
	public:
		friend IntegerBinom operator*(const IntegerBinom &a, const IntegerBinom &b);
		IntegerBinom& operator*=(IntegerBinom & binom);
		IntegerBinom& Mul(IntegerBinom &a, IntegerBinom &b);
        //�������� ���������� � �������
	public:
		IntegerBinom& Pow(IntegerBinom &a, Integer &n);
        //�������� ������ ��������� ��������
	public:
                IntegerBinom& Inverse();
		IntegerBinom& Inverse(IntegerBinom &a);
        // �������� ���������
        public:
		IntegerBinom& Generate();
                IntegerBinom& GenerateGenerative(std::vector<DecompositionMember>& mulGroupOrdDecomposition);
        // �������� ��������� ������ ������ �� �������
        public:
                std::vector<IntegerBinom> GenerateOneRootGroup(const Integer & rootDegree, std::vector<DecompositionMember>& mulGroupOrdDecomposition);
        // �������� ��������� ���������
        public:
                std::vector<IntegerBinom> GenerateSubGroup(const Integer & subGroupOrder, std::vector<DecompositionMember>& mulGroupOrdDecomposition);
        // �������� �������� ���������
        public:
                std::vector<IntegerBinom> MulMultitude(std::vector<IntegerBinom> & multitude, const IntegerBinom & binom);
        private:
                uint getMaxFactorizableGroupOrder() const;
                bool isParentGroupSmallEnoughForFactorization() const;
        // �������� ������ �� ��������
        public:
                static std::string MultitudeToString(std::vector<IntegerBinom> & multitude);
                static std::string FactorToString(std::vector<IntegerBinom> & factor, std::vector<std::vector<IntegerBinom> > & subGroups);
                static std::string FactorToTexString(std::vector<IntegerBinom> & factor, std::vector<std::vector<IntegerBinom> > & subGroups);
                std::string FactorToTexString(const Integer & rootDegree, std::vector<DecompositionMember>& mulGroupOrdDecomposition);
        };
};

#endif