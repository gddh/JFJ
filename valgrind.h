#ifndef LINKED_LIST_H
# define LINKED_LIST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "libft/libft.h"
#define malloc(X) my_malloc( X, __FILE__, __LINE__, __FUNCTION__)
#define free(X) my_free(X)
#define ft_memalloc(X) my_ft_memalloc( X, __FILE__, __LINE__, __FUNCTION__)
typedef struct	gddhs_list
{
	struct gddhs_list	*next;
	size_t			size;
	const char		*file;
	int				line;
	void			*p;
	const char		*func;
}				gddht_list;

void	push_front(gddht_list **lst, size_t size, const char *file, int line, const char *func, void *p);
int		find_and_free(gddht_list **lst, void *p);
void	*my_malloc(size_t size, const char *file, int line, const char *func);
void	*my_ft_memalloc(size_t size, const char *file, int line, const char *func);
void	my_free(void *ptr);
void	leaks();

#endif
