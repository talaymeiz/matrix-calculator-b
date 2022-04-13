
// #include "doctest.h"
// #include "Matrix.hpp"

// using namespace zich;
// TEST_CASE ("check Accounting operators") {

//     vector<double> vec1 = {1, 1, 1, 1, 1, 1, 1, 1, 1};
//     vector<double> vec2 = {2, 2, 2, 2, 2, 2, 2, 2, 2};
//     vector<double> vec3 = {3, 3, 3, 3, 3, 3, 3, 3, 3};

//     Matrix mat1{vec1, 3, 3};
//     Matrix mat11{vec1, 3, 3};
//     Matrix mat2{vec2, 3, 3};
//     Matrix mat3{vec3, 3, 3};
// 	CHECK(mat1+mat1 == mat2);
//     mat1=+mat1;
//     CHECK(mat1 == mat2);
//     mat1=+mat11;
//     CHECK(mat1 == mat3);
//     mat1=-mat11;
//     CHECK(mat1 == mat2);
//     mat1=-mat11;
//     CHECK(mat3-mat1 == mat2);
//     mat3-mat1;
//     CHECK(mat3 == mat2);
// }

// TEST_CASE ("check Comparison operators") {

//     vector<double> vec1 = {1, 1, 1, 1, 1, 1, 1, 1, 1};
//     vector<double> vec2 = {2, 2, 2, 2, 2, 2, 2, 2, 2};
//     vector<double> vec3 = {3, 3, 3, 3, 3, 3, 3, 3, 3};

//     Matrix mat1{vec1, 3, 3};
//     Matrix mat11{vec1, 3, 3};
//     Matrix mat2{vec2, 3, 3};
//     CHECK_EQ(mat1 == mat11, true);
//     CHECK_EQ(mat1 == mat2, false);
//     CHECK_EQ(mat1 != mat2, false);
//     CHECK_EQ(mat1 < mat2, true);
//     CHECK_EQ(mat2 < mat1, false);
//     CHECK_EQ(mat1 > mat2, false);
//     CHECK_EQ(mat1 <= mat11, true);
//     CHECK_EQ(mat2 >= mat1, true);
// }

// TEST_CASE ("check ++ / --") {

//     vector<double> vec1 = {1, 1, 1, 1, 1, 1, 1, 1, 1};
//     vector<double> vec2 = {2, 2, 2, 2, 2, 2, 2, 2, 2};
//     vector<double> vec3 = {3, 3, 3, 3, 3, 3, 3, 3, 3};

//     Matrix mat1{vec1, 3, 3};
//     Matrix mat11{vec1, 3, 3};
//     Matrix mat2{vec2, 3, 3};
//     Matrix mat3{vec3, 3, 3};
// 	CHECK(mat1+mat1 == mat2);
//     mat1=+mat1;
//     CHECK(mat1 == mat2);
//     mat1=+mat11;
//     CHECK(mat1 == mat3);
//     mat1=-mat11;
//     CHECK(mat1 == mat2);
//     mat1=-mat11;
//     CHECK(mat3-mat1 == mat2);
//     mat3-mat1;
//     CHECK(mat3 == mat2);
// }

// // TEST_CASE("Bad input erase") {
// //     ariel::Notebook notebook;
// //     CHECK_THROWS(notebook.erase(-4, 100, 50, Direction::Horizontal, 5));
// //     CHECK_THROWS(notebook.erase(10, -3, 50, Direction::Horizontal, 5));
// //     CHECK_THROWS(notebook.erase(9, 100, -7, Direction::Horizontal, 5));
// //     CHECK_THROWS(notebook.erase(6, 100, 102, Direction::Horizontal, 5));
// //     CHECK_THROWS(notebook.erase(10, 100, 95, Direction::Horizontal, -6));
// //     }
