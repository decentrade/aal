/*
    MPEI Algebraic Abstractions Library,
    2007-2011,
    Moscow Power Engineering Institute

        This file contains tests of the following classes:

*/


#include <iostream>
#include "./CppUnitLite/TestHarness.h"
#include "./AAF/AAL/Polynom.h"
#include "./AAF/AAL/PolynomGF3_m_6.h"
#include "./AAF/AAL/Matrix.h"
#include "./AAF/AAL/Integer.h"
#include "./AAF/AAL/DecompositionManager.h"
#include "./AAF/AAL/FactorizationAlgorithms.h"
#include <set>
using namespace AAL;

/*
	Конструкторы класса PolynomGF3_m_6
*/

TEST(PolynomGF3_m_6, EmptyConstructor)
{
	PolynomGF3_m_6 p;
	CHECK(p.isZero());
}

TEST(PolynomGF3_m_6, CopyConstructor)
{
	PolynomGF3_m_6 p("111", "000", "1010", "1100", "1010", "1100","");
    PolynomGF3_m_6 pp(p);
	CHECK(p==pp);
}

TEST(PolynomGF3_m_6, StringConstructor)
{
	PolynomGF3_m_6 p1("0","0","0","000","0","000",""), p2("","","","","","",""), p3("10","1","0","01","0","01","");
    PolynomGF3 a0("10");
	CHECK(p1.isZero());
	CHECK(p2.isZero());
	CHECK(p3.getA0() == a0);
}
TEST(PolynomGF3_m_6, Add)
{
        PolynomGF3_m_6 a("20010","22110","21102","21101","21222","11111","220001"),b("20121","12102","20120","22121","21220","22201","220001"),c,c2;
        PolynomGF3_m_6 d1("12221","12222","02221","01012","10102","10101","220001");
        PolynomGF3_m_6 a1("11201","02102","02021","20012","22021","21212","220001"),b1("01020","10120","00200","11000","21111","22222","220001"),c1,c3;
        PolynomGF3_m_6 d("10101","01212","11222","10222","12112","00012","220001");

        PolynomGF3_m_6 a2("11201","02102","02021","20012","22021","21212","220001"),b2("01020","10120","00200","11000","21111","22222","220001"),c4;
        PolynomGF3_m_6 d2("12221","12222","02221","01012","10102","10101","220001");
        PolynomGF3_m_6 a3("11021","11202","12100","11122","10022","20110","220001"),b3("12121","00220","21012","02121","21020","20120","220001"),c5;
        PolynomGF3_m_6 d3("20112","11122","00112","10210","01012","10200","220001");
        PolynomGF3_m_6 a4("21201","00012","20222","10201","02100","02020","220001"),b4("20002","01220","22110","12111","11011","10221","220001"),c6;
        PolynomGF3_m_6 d4("11200","01202","12002","22012","10111","12211","220001");
        PolynomGF3_m_6 a5("10011","00112","22010","10220","02200","10002","220001"),b5("22012","01001","21002","02102","01200","20001","220001"),c7;
        PolynomGF3_m_6 d5("02020","01110","10012","12022","00100","00000","220001");
        PolynomGF3_m_6 a6("21212","20220","02121","11101","10122","00102","220001"),b6("01220","11001","00002","11221","11200","20020","220001"),c8;
        PolynomGF3_m_6 d6("22102","01221","02120","22022","21022","20122","220001");
        PolynomGF3_m_6 a7("12210","01100","02102","20212","20020","11122","220001"),b7("00000","00101","22012","12211","00200","01201","220001"),c9;
        PolynomGF3_m_6 d7("12210","01201","21111","02120","20220","12020","220001");
        PolynomGF3_m_6 a8("10122","01210","00112","22211","00010","02022","220001"),b8("11102","21010","22222","01101","20121","02020","220001"),c10;
        PolynomGF3_m_6 d8("21221","22220","22001","20012","20101","01012","220001");
        PolynomGF3_m_6 a9("11111","20012","10201","00210","02020","10122","220001"),b9("11012","20112","21012","01022","11010","11000","220001"),c11;
        PolynomGF3_m_6 d9("22120","10121","01210","01202","10000","21122","220001");
        PolynomGF3_m_6 a10("02201","12112","22012","22212","21101","21101","220001"),b10("01220","01110","01022","00112","20020","12211","220001"),c12;
        PolynomGF3_m_6 d10("00121","10222","20001","22021","11121","00012","220001");

        c1 = a1 + b1;
        CHECK(c1 == d1);
        c2 = a + b;
        CHECK(c2 == d);
        CHECK(c3.Add(a1,b1) == d1);
        CHECK(c.Add(a,b) == d);

        b += a;
        CHECK(b == d);
        CHECK(a + b == b + a);
        CHECK((a + b) + c == a + (b + c));

        CHECK(c4.Add(a2,b2) == d2);
        CHECK(c5.Add(a3,b3) == d3);
        CHECK(c6.Add(a4,b4) == d4);
        CHECK(c7.Add(a5,b5) == d5);
        CHECK(c8.Add(a6,b6) == d6);
        CHECK(c9.Add(a7,b7) == d7);
        CHECK(c10.Add(a8,b8) == d8);
        CHECK(c11.Add(a9,b9) == d9);
        CHECK(c12.Add(a10,b10) == d10);

}
TEST(PolynomGF3_m_6, Mul)
{

        PolynomGF3_m_6 a("20000","01200","00010","12102","11110","01101","220001"),b("10012","22021","21021","01102","10112","21022","220001"),c,c2;
        PolynomGF3_m_6 d("10011","10020","20211","22101","20212","21101","220001");

        PolynomGF3_m_6 a1("00100","11002","02200","10202","01112","10110","220001"),b1("11020","12222","22111","22002","11000","20220","220001"),c3;
        PolynomGF3_m_6 d1("11102","20111","20020","22020","22010","00110","220001");
        PolynomGF3_m_6 a2("01122","01221","00210","11111","21010","01121","220001"),b2("22210","20112","21220","02220","12100","01001","220001"),c4;
        PolynomGF3_m_6 d2("20000","01111","00201","01112","11000","21212","220001");
        PolynomGF3_m_6 a3("20020","21002","11212","00001","22101","12100","220001"),b3("10020","01122","00110","10011","00001","21010","220001"),c5;
        PolynomGF3_m_6 d3("10212","21100","02110","02020","00221","12001","220001");
        PolynomGF3_m_6 a4("02212","21221","11110","01121","21001","12020","220001"),b4("10011","22020","22002","11011","02111","10220","220001"),c6;
        PolynomGF3_m_6 d4("01100","22001","00000","21011","12012","00201","220001");
        PolynomGF3_m_6 a5("21212","21101","22202","00020","22221","01010","220001"),b5("10022","01211","22101","00121","10021","10022","220001"),c7;
        PolynomGF3_m_6 d5("10002","11020","12222","22010","11012","02011","220001");
        PolynomGF3_m_6 a6("02002","01021","22000","22201","20221","21000","220001"),b6("12122","21111","11112","22200","01220","02022","220001"),c8;
        PolynomGF3_m_6 d6("02120","20111","10201","12022","20222","12222","220001");
        PolynomGF3_m_6 a7("22021","10112","01201","10000","01020","12120","220001"),b7("12211","12222","00221","22121","22111","22222","220001"),c9;
        PolynomGF3_m_6 d7("12110","20011","02011","22121","21200","10211","220001");
        PolynomGF3_m_6 a8("11201","01101","01002","02202","11002","00011","220001"),b8("10022","12112","00212","12010","11220","21220","220001"),c10;
        PolynomGF3_m_6 d8("22020","12122","10112","01121","21212","02202","220001");


/*        PolynomGF3_m_6 a11("1","0","0","0","0","1","211"),b11("0","1","1","1","1","2","211");
        PolynomGF3_m_6 d11("1","0","0","0","0","0","211");
        CHECK(a11*b11 == d11);
*/
        c2 = a * b;
        CHECK(c.Mul(a,b) == d);
        CHECK(c2 == d)
        b *= a;
        CHECK(b == d);
        CHECK(a*b == b*a);
        CHECK((a + b)*c == (a*c + b*c));

        CHECK(c3.Mul(a1,b1) == d1);
        CHECK(c4.Mul(a2,b2) == d2);
        CHECK(c5.Mul(a3,b3) == d3);
        CHECK(c6.Mul(a4,b4) == d4);
        CHECK(c7.Mul(a5,b5) == d5);
        CHECK(c8.Mul(a6,b6) == d6);
        CHECK(c9.Mul(a7,b7) == d7);
        CHECK(c10.Mul(a8,b8) == d8);


}

TEST(PolynomGF3_m_6, Pow)
{
        PolynomGF3_m_6 a("20020","22021","02020","12011","01011","12000","220001"),d("11202","11212","21101","22121","01111","00220","220001"),c;
        PolynomGF3_m_6 a1("22112","22200","20022","20212","10202","20201","220001"),d1("22221","20020","11210","11122","10121","12112","220001");
	PolynomGF3_m_6 a2("22001","01100","20020","12211","02112","20020","220001"),d2("21020","20221","01110","11011","12002","21112","220001");
        PolynomGF3_m_6 a3("10212","00212","00201","10002","20202","10212","220001"),d3("10202","21022","21211","22210","12221","21000","220001");
        PolynomGF3_m_6 a4("00012","20012","02022","12010","21222","12201","220001"),d4("11111","11110","21022","12200","00221","00221","220001");
        PolynomGF3_m_6 a5("00212","01121","20012","01002","11200","12020","220001"),d5("22210","20022","22000","00220","01202","20211","220001");
        PolynomGF3_m_6 a6("21002","21201","02111","01012","21122","12220","220001"),d6("21012","10211","11102","02221","20100","22102","220001");
        PolynomGF3_m_6 a7("02221","01001","22110","01201","22011","11010","220001"),d7("20100","22002","22002","10112","01121","22001","220001");
        PolynomGF3_m_6 a8("12122","00220","12211","12120","01022","00121","220001"),d8("00110","20101","01111","01120","10021","12011","220001");
        PolynomGF3_m_6 a9("10121","21122","00001","02000","01011","10221","220001"),d9("10210","11221","21002","01222","10010","10101","220001");

          CHECK(c.Pow(a,AAL::Integer(1100)) == d);
          CHECK(c.Pow(a1,AAL::Integer(919)) == d1);
          CHECK(c.Pow(a2,AAL::Integer(154)) == d2);
          CHECK(c.Pow(a3,AAL::Integer(548)) == d3);
         CHECK(c.Pow(a4,AAL::Integer(765)) == d4);
    CHECK(c.Pow(a5,AAL::Integer(58)) == d5);
    CHECK(c.Pow(a6,AAL::Integer(402)) == d6);
    CHECK(c.Pow(a7,AAL::Integer(1191)) == d7);
    CHECK(c.Pow(a8,AAL::Integer(152)) == d8);
    CHECK(c.Pow(a9,AAL::Integer(93)) == d9);

}
TEST(PolynomGF3_m_6, Cube)
{
        PolynomGF3_m_6 a("1","0","0","1","0","0","220001"),d("1","0","0","1","2","0","220001"),c;
        PolynomGF3_m_6 a1("1","2","2","2","0","0","220001"),d1("0","1","0","1","1","0","220001");
        CHECK(c.Cube(a) == d);
        CHECK(c.Cube(a1) == d1);
        CHECK(c.Cube(a) == a*a*a);
}
TEST(PolynomGF3_m_6, CubeRoot)
{
        PolynomGF3_m_6 a("12012","02000","00012","12100","02002","10020","220001"),c,d("02010","10011","00102","02010","22211","12000","220001");
    PolynomGF3_m_6 a1("20121","02021","10020","01022","20220","01202","220001"),d1("02202","11110","12102","10102","12000","10220","220001");
    PolynomGF3_m_6 a2("11220","11022","21221","02021","12201","10222","220001"),d2("02212","00222","12002","22010","20101","11002","220001");
    PolynomGF3_m_6 a3("22010","00212","02102","00202","01112","22222","220001"),d3("12010","01121","02200","21100","02202","10111","220001");
    PolynomGF3_m_6 a4("10100","10210","21011","01220","00220","21011","220001"),d4("02010","12110","22222","01222","11010","11010","220001");
    PolynomGF3_m_6 a5("01212","20210","01220","02120","22021","01210","220001"),d5("01020","20201","22221","00111","21012","20012","220001");
    PolynomGF3_m_6 a6("01012","22210","12110","10021","00112","02222","220001"),d6("10020","22020","01121","12021","22021","20111","220001");
    PolynomGF3_m_6 a7("21022","20202","20020","22101","22211","02110","220001"),d7("02101","22120","00001","12002","22000","12021","220001");
    PolynomGF3_m_6 a8("00221","11222","00001","10012","20201","22010","220001"),d8("20222","22200","20202","00202","12122","10112","220001");
    PolynomGF3_m_6 a9("12111","00102","20012","00110","11211","11112","220001"),d9("20111","01021","02121","20210","12211","02011","220001");

    PolynomGF3 module("220001"),mod("220001");
//    c.CubeRoot(a2,mod);
//    c.CubeRoot(a1,mod);
 //   c.CubeRoot(a,module);
 //   c1.CubeRoot(a,module);
    CHECK(c.CubeRoot(a,module) == d);
    CHECK(c*c*c == a);

    CHECK(c.CubeRoot(a1,module) == d1);
    CHECK(c.CubeRoot(a2,module) == d2);
    CHECK(c.CubeRoot(a3,module) == d3);
    CHECK(c.CubeRoot(a4,module) == d4);
    CHECK(c.CubeRoot(a5,module) == d5);
    CHECK(c.CubeRoot(a6,module) == d6);
    CHECK(c.CubeRoot(a7,module) == d7);
    CHECK(c.CubeRoot(a8,module) == d8);
    CHECK(c.CubeRoot(a9,module) == d9);

}
//--------------------------------------------------------------------------------------
TEST(PolynomGF3_m_6, elementOrder)
{
  PolynomGF3_m_6 u, u1, u2, a("1","2","2","2","0","0","220001"), a1,a2;
  PolynomGF3 mod("220001");
  AAL::Integer ord(1);
  int m = mod.getNumberBits() - 1;
  ord = ord.Pow(3, 6* m);
  ord = ord - 1;
//  a1.Pow(a,2);
//  a2.Pow(a,3);
  std::string s = ord.ToString();
  FactorizationAlgorithms w(ord);
  std::vector<DecompositionMember> vector = w.ProbingDivisionAlgorithmDecomposition();
  AAL::Integer t = u.elementOrder(mod, a,vector,ord);
  AAL::Integer t1 = u1.elementOrder(mod, a1.Pow(a,AAL::Integer(3)),vector,ord);
  AAL::Integer t2 = u2.elementOrder(mod, a2.Pow(a,AAL::Integer(77)),vector,ord);

  CHECK(t == t1);
  CHECK(t/7 == t2);
}
//--------------------------------------------------------------------------------------
TEST(PolynomGF3_m_6, isGenerator)
{
  PolynomGF3_m_6 u, u1,a1, a("1","2","2","2","0","0","220001");
  PolynomGF3 mod("220001");
  int m = mod.getNumberBits() - 1;
  AAL::Integer ord(1);
  ord = ord.Pow(3, 6* m);
  ord = ord - 1;
  a1.Pow(a,AAL::Integer(7));
  FactorizationAlgorithms w(ord);
  bool r;
  std::vector<DecompositionMember> vector = w.ProbingDivisionAlgorithmDecomposition();
  ord = ord + 1;
  r = u.isGenerator(mod, a,vector,ord);
  CHECK(r == false);
  r = u1.isGenerator(mod, a1,vector,ord);
  CHECK(r == false);
}

//--------------------------------------------------------------------------------------
TEST(PolynomGF3_m_6, Generate)
{
  PolynomGF3_m_6 u;
  PolynomGF3 mod("220001");
  u.Generate(mod);
  std::string s = u.getA0().ToString();
  s = u.getA1().ToString();
  s = u.getA2().ToString();
  s = u.getA3().ToString();
  s = u.getA4().ToString();
  s = u.getA5().ToString();
  CHECK(true);
}
//-------------------------------------------------------------------------------
TEST(PolynomGF3_m_6, LegendreSymbol)
{
  PolynomGF3_m_6 a("112","2021","11201","0022","0122","21122","220001"),c1,c2;
  PolynomGF3_m_6 a1("2101","2111","1202","01021","2021","0102","220001");
  PolynomGF3_m_6 a2("10120","02122","0110","10211","11000","20222","220001");
  PolynomGF3_m_6 one("1","0","0","0","0","0","220001");
  PolynomGF3_m_6 two("2","0","0","0","0","0","220001");
  PolynomGF3 mod("220001");
  CHECK(c1.LegendreSymbol(a2,mod) == two);
  CHECK(c1.LegendreSymbol(a,mod) == two);
  CHECK(c1.LegendreSymbol(a1,mod) == one);
}

//--------------------------------------------------------------------------------------
TEST(PolynomGF3_m_6, Sqrt)
{
  PolynomGF3_m_6 a22("1","2","2","2","0","0","220001"),c;
  PolynomGF3_m_6 a11("02202","20120","02100","21001","12220","21120","220001"),c1;
  PolynomGF3_m_6 a12("01100","01210","22101","11111","11002","20220","220001");

  PolynomGF3_m_6 a("02111","11100","12102","02001","11200","10110","220001"),d("0","0","0","0","0","0","220001");
  PolynomGF3_m_6 a1("10010","22212","00001","21211","22012","10200","220001"),d1("22112","10022","02001","02010","20221","01022","220001");
  PolynomGF3_m_6 a2("21101","02000","10201","00122","20001","20221","220001"),d2("0","0","0","0","0","0","220001");
  PolynomGF3_m_6 a3("11201","11121","11101","10002","20222","10201","220001"),d3("12101","10222","00110","12002","22111","12121","220001");
  PolynomGF3_m_6 a4("10200","21211","02101","12100","02220","22222","220001"),d4("0","0","0","0","0","0","220001");
  PolynomGF3_m_6 a5("02202","20221","12111","01012","10110","21210","220001"),d5("0","0","0","0","0","0","220001");
  PolynomGF3_m_6 a6("10200","12122","11220","21001","22012","02010","220001"),d6("01220","02012","12022","10122","02020","12201","220001");
  PolynomGF3_m_6 a7("11111","01111","20202","11222","21021","00222","220001"),d7("11001","12201","12100","22110","22021","02112","220001");
  PolynomGF3_m_6 a8("01111","10021","21010","20211","02212","00112","220001"),d8("11012","12200","12111","11120","01210","01112","220001");
  PolynomGF3_m_6 a9("21111","10121","21212","02102","20200","02020","220001"),d9("01121","21221","00000","20202","01112","11002","220001");


  PolynomGF3 mod("220001");
  int m = mod.getNumberBits() - 1;
  AAL::Integer ord(1);
  ord = ord.Pow(3, 6* m);
  ord = ord - 1;
  AAL::Integer two_pow("0"),div,copy_ord;
  copy_ord = ord;
  div = ord%2;
  ord = ord/2;
  std::string str = div.ToString();
  while(div == 0)
  {
        two_pow++;
        ord = ord/2;
        str = ord.ToString();
        div = ord%2;
        str = div.ToString();
  }
  str = two_pow.ToString();
  AAL::Integer s,T,i;

  T = two_pow;
  s = ord;
  str = s.ToString();
  c.Sqrt(a11,mod,s,T);
  c1.Sqrt(a12,mod,s,T);
  CHECK(c1*c1 == a12);
  CHECK(c.isZero());

  CHECK(c.Sqrt(a,mod,s,T) == d);
CHECK(c.Sqrt(a1,mod,s,T) == d1);
  CHECK(d1*d1 == a1);
CHECK(c.Sqrt(a2,mod,s,T) == d2);
CHECK(c.Sqrt(a3,mod,s,T) == d3);
  CHECK(c*c == a3);
CHECK(c.Sqrt(a4,mod,s,T) == d4);
CHECK(c.Sqrt(a5,mod,s,T) == d5);

c.Sqrt(a6,mod,s,T);
  CHECK(c*c == a6);

 c.Sqrt(a7,mod,s,T);
  CHECK(c*c == a7);

  c.Sqrt(a8,mod,s,T);
  CHECK(c*c == a8);

  c.Sqrt(a9,mod,s,T);
  CHECK(c*c == a9);

}
//--------------------------------------------------------------------------------------
TEST(PolynomGF3_m_6, Inverse)
{
        PolynomGF3_m_6 a3("01100","01210","22101","11111","11002","20220","220001"),c1,c11;
        PolynomGF3_m_6 a4("02200","02120","11202","22222","22001","10110","220001");
        PolynomGF3_m_6 d1("22122","10020","22022","02222","21212","22001","220001"), d2("11211","20010","11011","01111","12121","11002","220001");
        PolynomGF3_m_6 one("1","0","0","0","0","0","220001"),m;
        PolynomGF3 module1("220001");
        PolynomGF3_m_6 a1("1","0","0","0","0","1","220001"),d11("0","1","0","0","0","0","220001");

    CHECK(c1.Inverse(a1,module1) == d11);

    std::string s = c1.getA0().ToString();
    s =  c1.getA1().ToString();
    s = c1.getA2().ToString();
    s = c1.getA3().ToString();
    s = c1.getA4().ToString();
    s = c1.getA5().ToString();
    c11 = c1.Inverse(a3,module1);
    CHECK(c11 == d1);
    s = c11.getA0().ToString();
    s = c11.getA1().ToString();
    s = c11.getA2().ToString();
    s = c11.getA3().ToString();
    s = c11.getA4().ToString();
    s = c11.getA5().ToString();
    CHECK(c1.Inverse(a4,module1)*a4 == one);
}
//----------------------------------------------------------------------------------
TEST(PolynomGF3_m_6, getRo)
{
        PolynomGF3_m_6 one("1","0","0","0","0","0","220001"),m,c,c1;
        PolynomGF3 module1("220001");
        PolynomGF3_m_6 a1("1","0","0","0","0","0","220001"),d11("0","1","0","0","0","0","220001");

//    CHECK(c1.getRo(a1,module1) == d11);

    std::string s = c1.getA0().ToString();
    s =  c1.getA1().ToString();
    s = c1.getA2().ToString();
    s = c1.getA3().ToString();
    s = c1.getA4().ToString();
    s = c1.getA5().ToString();
}


