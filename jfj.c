#include "jfj.h"
 //#include "libft/libft.h"
#undef malloc
#undef free
#undef ft_memalloc

/* Don't edit this line */
gddht_list *list = NULL;


/* COMMENT OUT THE PRINTFS AND FT_FUNCTIONS AS NECESSARY */
int		free_node(gddht_list **lst, gddht_list *next, gddht_list *tmp)
{
	*lst = next;
	printf("Freeing: %s, %i, %s, %p[%li]\n", tmp->file, tmp->line, tmp->func, tmp->p, tmp->size);
	free(tmp);
	return(1);
}

int		free_node1(gddht_list *tmp, gddht_list *next)
{
	tmp->next = next->next;
	printf("Freeing: %s, %i, %s, %p[%li]\n", next->file, next->line, next->func, next->p, next->size);
	free(next);
	return(1);
}

void	*my_malloc(size_t size, const char *file, int line, const char *func)
{
	void *p = malloc(size);
	printf("Need to Free: %s, %i, %s, %p[%li]\n", file, line, func, p, size);
	push_front(&list, size, file, line, func, p);
	return (p);
}

//void	*my_ft_memalloc(size_t size, const char *file, int line, const char *func)
//{
//	void *p = ft_memalloc(size);
//	printf("Need to Free: %s, %i, %s, %p[%li]\n", file, line, func, p, size);
//	push_front(&list, size, file, line, func, p);
//	return (p);
//}

/***********************************************************************/
/* YOU SHOULD NOT NEED TO GO BELOW JUST TO USE. FEEL FREE TO CONTINUE  */
/***********************************************************************/

gddht_list	*create_new(size_t size, const char *file, int line, const char *func, void *p)
{
	gddht_list *tmp;

	tmp = (gddht_list *) malloc(sizeof(gddht_list));
	if (tmp)
	{
		tmp->size = size;
		tmp->file = file;
		tmp->line = line;
		tmp->func = func;
		tmp->p = p;
		tmp->next = NULL;
	}
	return (tmp);
}

void	push_front(gddht_list **lst, size_t size, const char *file, int line, const char *func, void *p)
{
	gddht_list *tmp;

	if (lst)
	{
		tmp = *lst;
		*lst = create_new(size, file, line, func, p);
		(*lst)->next = tmp;
	}
	else
		*lst = create_new(size, file, line, func, p);
}

int		find_and_free(gddht_list **lst, void *p)
{
	gddht_list *tmp;
	gddht_list *next;

	if (*lst)
	{
		tmp = *lst;
		next = (*lst)->next;
		if (tmp->p == p)
			return (free_node(lst, next, tmp));
		else
		{
			while (next)
			{
				if (next->p == p)
					return free_node1(tmp, next);
				tmp = next;
				next = next->next;
			}
		}
	}
	return(0);
}

void	my_free(void *ptr)
{
	if (!find_and_free(&list, ptr))
		printf("cannot find to free\n");
}

void	leaks()
{
	gddht_list *lst;

	lst = list;
	if (lst)
	{
		while(lst)
		{
			printf("Need to Free: %s, %i, %s, %p[%li]\n", lst->file, lst->line, lst->func, lst->p, lst->size);
			lst = lst->next;
		}
	}
	else
		printf("No memory leaks detected.\n");
}
