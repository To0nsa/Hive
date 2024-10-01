/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:37:33 by nlouis            #+#    #+#             */
/*   Updated: 2024/09/22 16:55:26 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ABS_H
# define FT_ABS_H

# define ABS(Value) (Value * ((Value < 0) * (-1) + (Value > 0)))

#endif

/* This expression calculates the absolute value of Value. 
Here's a breakdown:

Condition Checks:

(Value < 0): Returns 1 if Value is negative, otherwise 0.
(Value > 0): Returns 1 if Value is positive, otherwise 0.
Scaling Factor:

If Value is negative: (1 * -1) + 0 = -1
If Value is positive: 0 + (1 * 1) = 1
If Value is zero: 0 + 0 = 0
Final Calculation:

Value * (-1) if negative → -Value
Value * 1 if positive → Value
Value * 0 if zero → 0
In summary: The entire expression transforms Value into its 
absolute value by negating it if it's negative, leaving it 
unchanged if positive, and keeping it zero if it's zero.

Example:

If Value = -5, then -5 * (-1) = 5
If Value = 3, then 3 * 1 = 3
If Value = 0, then 0 * 0 = 0
This approach mimics the behavior of an absolute value 
function without using built-in functions. */