/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:50:58 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/12 14:22:12 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_matrix	mul_matrix(t_matrix a, t_matrix b)
{
	size_t	row;
	size_t	col;
	size_t	aux;
	double	m[MAT_MAX][MAT_MAX];

	if (a.size != b.size)
		return (create_identity_matrix());
	ft_bzero(m, (sizeof(double) * MAT_SQR));
	row = 0;
	while (row < a.size)
	{
		col = 0;
		while (col < a.size)
		{
			aux = 0;
			while (aux < a.size)
			{
				m[row][col] += a.matrix[row][aux] * b.matrix[aux][col];
				++aux;
			}
			++col;
		}
		++row;
	}
	return (create_matrix(a.size, m));
}

t_tuple	mul_matrix_tuple(t_matrix m, t_tuple t)
{
	size_t	row;
	double	aux[MAT_MAX];

	if (m.size != MAT_MAX)
		return (create_tuple(0, 0, 0, 0));
	row = 0;
	while (row < MAT_MAX)
	{
		aux[row] = \
			(m.matrix[row][0] * t.x) + \
			(m.matrix[row][1] * t.y) + \
			(m.matrix[row][2] * t.z) + \
			(m.matrix[row][3] * t.w);
		++row;
	}
	return (create_tuple(aux[0], aux[1], aux[2], aux[3]));
}

t_matrix	transpose_matrix(t_matrix m)
{
	size_t	row;
	size_t	col;
	double	transpose[MAT_MAX][MAT_MAX];

	row = 0;
	while (row < m.size)
	{
		col = 0;
		while (col < m.size)
		{
			transpose[col][row] = m.matrix[row][col];
			++col;
		}
		++row;
	}
	return (create_matrix(m.size, transpose));
}

t_matrix	inverse_matrix(t_matrix m)
{
	const double	_determinant = determinant(m);
	size_t			row;
	size_t			col;
	double			inverse[MAT_MAX][MAT_MAX];

	if (!_determinant)
		return (create_identity_matrix());
	row = 0;
	while (row < m.size)
	{
		col = 0;
		while (col < m.size)
		{
			inverse[col][row] = cofactor(m, row, col) / _determinant;
			++col;
		}
		++row;
	}
	return (create_matrix(m.size, inverse));
}
