/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:45:47 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/10 13:03:58 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORFT_H
# define VECTORFT_H

# include <math.h>

typedef struct s_vector3
{
	float	x;
	float	y;
	float	z;
}	t_vector3;

typedef struct s_vector2
{
	float	x;
	float	y;
}	t_vector2;

	/////////////////////////////////////////
	//////////// VECTOR3 FUNCTIONS //////////
	/////////////////////////////////////////

/**
 * @brief Add two vector3
 * 
 * @param a vector3 a
 * @param b	vector3 b
 * 
 * @return t_vector3
*/
t_vector3	add_vector3(t_vector3 a, t_vector3 b);

/**
 * @brief Substract two vector3
 * 
 * @param a vector3 a
 * @param b	vector3 b
 * 
 * @return t_vector3
*/
t_vector3	sub_vector3(t_vector3 a, t_vector3 b);

/**
 * @brief Dot product of two vector3
 * 
 * @param a vector3 a
 * @param b	vector3 b
 * 
 * @return result of dot product
*/
float		dot_vector3(t_vector3 a, t_vector3 b);

/**
 * @brief Cross product of two vector3
 * 
 * @param a vector3 a
 * @param b	vector3 b
 * 
 * @return t_vector3
*/
t_vector3	cross_vector3(t_vector3 a, t_vector3 b);

/**
 * @brief Normalize a vector3 adjust the lenght of the vector to 1
 * 	and keep the direction
 * 
 * @param a vector3 a
 * 
 * @return normalized vector3
*/
t_vector3	normalize_vector3(t_vector3 a);

/**
 * @brief Get the magnitude of a vector3
 * 
 * @param a vector3 a
 * 
 * @return magnitude of vector3
*/
float		magnitude_vector3(t_vector3 a);

/**
 * @brief Create a vector3 object
 * 
 * @param x x coordinate
 * @param y y coordinate
 * @param z z coordinate
 * 
 * @return t_vector3
*/
t_vector3	vector3(float x, float y, float z);

	/////////////////////////////////////////
	//////////// VECTOR2 FUNCTIONS //////////
	/////////////////////////////////////////

/**
 * @brief Add two vector2
 * 
 * @param a vector2 a
 * @param b	vector2 b
 * 
 * @return t_vector2
*/
t_vector2	add_vector2(t_vector2 a, t_vector2 b);

/**
 * @brief Substract two vector2
 * 
 * @param a vector2 a
 * @param b	vector2 b
 * 
 * @return t_vector2
*/
t_vector2	sub_vector2(t_vector2 a, t_vector2 b);

/**
 * @brief Dot product of two vector2
 * 
 * @param a vector2 a
 * @param b	vector2 b
 * 
 * @return result of dot product
*/
float		dot_vector2(t_vector2 a, t_vector2 b);

/**
 * @brief Cross product of two vector2
 * 
 * @param a vector2 a
 * @param b	vector2 b
 * 
 * @return 
 * @details cross product of two vector2 
*/
float		cross_vector2(t_vector2 a, t_vector2 b);

/**
 * @brief Normalize a vector2 adjust the lenght of the vector to 1
 * 	and keep the direction
 * 
 * @param a vector2 a
 * 
 * @return normalized vector2
*/
t_vector2	normalize_vector2(t_vector2 a);

/**
 * @brief Get the magnitude of a vector2
 * 
 * @param a vector2 a
 * 
 * @return magnitude of vector2
*/
float		magnitude_vector2(t_vector2 a);

/**
 * @brief Create a vector2 object
 * 
 * @param x x coordinate
 * @param y y coordinate
 * 
 * @return t_vector2
*/
t_vector2	vector2(float x, float y);

#endif // VECTORFT_H