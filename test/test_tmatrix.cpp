#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<double> c(2),c2(2);
	c[0][0] = 1;
	c[0][1] = 2;
	c[1][0] = 3;
	c[1][1] = 4;
	TDynamicMatrix<double> c1(c);
	EXPECT_EQ(c1, c);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<double> c(2);
	c[0][0] = 1;
	c[0][1] = 2;
	c[1][0] = 3;
	c[1][1] = 4;
	TDynamicMatrix<double> c1(c);
	c[0][0] = 3;
	EXPECT_EQ(c[0][0]==c1[0][0], false);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<double> c(3);
	EXPECT_EQ(3,c.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<double> c(5);
	c[0][4] = 3.0;
	c[3][1] = 5.0;
	double c1 = c[3][1];
	EXPECT_EQ(c1, 5.0);
	EXPECT_EQ(c[0][4], 3.0);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<double> c(5);
	ASSERT_ANY_THROW(c.at(1).at(-1) = 3);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<double> c(5);
	ASSERT_ANY_THROW(c.at(500).at(500) = 3);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<double> c(2),c1(2);
	c[0][0] = 1; c1[0][0] = 1;
	c[0][1] = 2; c1[0][1] = 2;
	c[1][0] = 3; c1[1][0] = 3;
	c[1][1] = 4; c1[1][1] = 4;
	c = c;
	EXPECT_EQ(c,c1);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<double> c(2), c1(2),c2(2);
	c[0][0] = 1; c1[0][0] = 1;
	c[0][1] = 2; c1[0][1] = 2;
	c[1][0] = 3; c1[1][0] = 3;
	c[1][1] = 4; c1[1][1] = 4;
	c2 = c;
	EXPECT_EQ(c2, c1);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<double> c(2), c1(2), c2(1);
	c2[0] = 13;
	c[0][0] = 1; c1[0][0] = 1;
	c[0][1] = 2; c1[0][1] = 2;
	c[1][0] = 3; c1[1][0] = 3;
	c[1][1] = 4; c1[1][1] = 4;
	c2 = c;
	EXPECT_EQ(c2.size(), c1.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<double> c(2), c1(2), c2(1);
	c2[0] = 13;
	c[0][0] = 1; c1[0][0] = 1;
	c[0][1] = 2; c1[0][1] = 2;
	c[1][0] = 3; c1[1][0] = 3;
	c[1][1] = 4; c1[1][1] = 4;
	c2 = c;
	EXPECT_EQ(c2, c1);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<double> c(2), c1(2);
	c[0][0] = 1; c1[0][0] = 1;
	c[0][1] = 2; c1[0][1] = 2;
	c[1][0] = 3; c1[1][0] = 3;
	c[1][1] = 4; c1[1][1] = 4;
	EXPECT_EQ(c==c1,true);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<double> c(2);
	c[0][0] = 1;
	c[0][1] = 2;
	c[1][0] = 3;
	c[1][1] = 4;
	EXPECT_EQ(c == c, true);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<double> c(2), c1(3);
	c[0][0] = 1; c1[0][0] = 1;
	c[0][1] = 2; c1[0][1] = 2;
	c[1][0] = 3; c1[1][0] = 3;
	c[1][1] = 4; c1[1][1] = 4;
	EXPECT_EQ(c == c1, false);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<double> c(2), c1(2),c2(2);
	c[0][0] = 1; c1[0][0] = 1; c2[0][0] = 2;
	c[0][1] = 2; c1[0][1] = 2; c2[0][1] = 4;
	c[1][0] = 3; c1[1][0] = 3; c2[1][0] = 6;
	c[1][1] = 4; c1[1][1] = 4; c2[1][1] = 8;
	EXPECT_EQ(c+c1, c2);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<double> c(2), c1(3);
	c[0][0] = 1; c1[0][0] = 1;
	c[0][1] = 2; c1[0][1] = 2;
	c[1][0] = 3; c1[1][0] = 3;
	c[1][1] = 4; c1[1][1] = 4;
	ASSERT_ANY_THROW(c + c1);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<double> c(2), c1(2), c2(2);
	c[0][0] = 1; c1[0][0] = 1; c2[0][0] = 0;
	c[0][1] = 2; c1[0][1] = 2; c2[0][1] = 0;
	c[1][0] = 3; c1[1][0] = 3; c2[1][0] = 0;
	c[1][1] = 4; c1[1][1] = 4; c2[1][1] = 0;
	EXPECT_EQ(c - c1, c2);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<double> c(2), c1(3);
	c[0][0] = 1; c1[0][0] = 1;
	c[0][1] = 2; c1[0][1] = 2;
	c[1][0] = 3; c1[1][0] = 3;
	c[1][1] = 4; c1[1][1] = 4;
	ASSERT_ANY_THROW(c - c1);
}

