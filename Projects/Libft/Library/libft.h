/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
#define LIBFT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ft_isalpha(int n);

int ft_isdigit(int n);

int ft_isalnum(int n);

int ft_isascii(int n);

int ft_isprint(int n);

int ft_strlen(const char *str);

void    *ft_memset(void *dest, int ch, size_t len);

void    ft_bzero(void *dest, size_t len);

void    *ft_memcpy(void *dest, const void *src, size_t len);

void    *ft_memmove(void *dest, const void *src, size_t len);

size_t  ft_strlcpy(char *dest, const char *src, size_t n);

size_t  ft_strlcat(char *dest, const char *src, size_t n);

int ft_toupper(int n);

int ft_tolower(int n);

char    *ft_strchr(const char *str, int c);

char    *ft_strrchr(const char *str, int c);

int ft_strncmp(const char *str_ref, const char *str_base, size_t n);

int ft_memcmp(const void *ptr1, const void * ptr2, size_t n);

char    *ft_strnstr(const char *src, const char *find, size_t n);

int ft_atoi(const char *str);

void    *ft_calloc(size_t count, size_t size);

char    *ft_strdup(const char *src);

char    *ft_subtstr(char const *s, unsigned int start, size_t len);

char    *ft_strjoin(char const *s1, char const *s2);

char    *ft_strtrim(char const *s1, char const *set);

char    **ft_split(char const *s, char c);

char    *ft_itoa(int n);

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))

#endif