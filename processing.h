/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelsweyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:33:22 by lelsweyr          #+#    #+#             */
/*   Updated: 2020/12/09 19:54:03 by lelsweyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESSING_H
# define PROCESSING_H

# include "parcer.h"

void	processing(t_sign *st, va_list qp);
void	processing_percent(t_sign *st);
void	processing_pointer(t_sign *st, size_t arg);
void	proc_pp(t_sign *st, char *a, int len, char *d);
char	*proc_p(char *d, size_t c, t_sign *st);
char	*proc_x(char *d, unsigned c, t_sign *st);
void	processing_int(t_sign *st, int arg);
void	processing_char(t_sign *st, char arg);
void	processing_str(t_sign *st, char *arg);
void	processing_u_x(t_sign *st, unsigned c);
void	proc_d_i(char *d, int len, t_sign *st);
void	proc_u(char *d, int len, t_sign *st);
void	case_1(char *arg, int len, t_sign *st);
void	case_2(t_sign *st, char *arg, int len);
void	case_2_1(t_sign *st, char *arg, int len);
void	case_2_2(t_sign *st, char *arg, int len, int flag);
void	case_3(t_sign *st, char *arg, int len);
void	case_4(t_sign *st, char *arg, int len);
void	case_4_1(t_sign *st, int flag, char *arg, int len);
void	case_str1(t_sign *st, char *arg, int len);
void	case_str1_1(t_sign *st, char *arg, int len);
void	case_str2(t_sign *st, char *arg, int len);
void	case_str3(t_sign *st, char *arg, int len);
void	case_str3_1(t_sign *st, char *arg, int len);
void	case_str3_2(t_sign *st, char *arg, int len);
void	case_str4(t_sign *st, char *arg, int len);
void	case_1p(char *d, int len, t_sign *st, char *a);
void	case_2p(char *d, int len, t_sign *st, char *a);
void	case_3p(char *d, int len, t_sign *st, char *a);
void	case_4p(char *d, int len, t_sign *st, char *a);
int		num_len(size_t arg);
char	*ft_bzero(char *s, int n);
int		ft_null(t_sign *st, char *d, int len);
void	ft_length(t_sign *st, int len);
void	ft_length_p(t_sign *st, int len);
int		ft_strlen(char *str);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned n);
int		ft_atoi(char *str);

#endif
