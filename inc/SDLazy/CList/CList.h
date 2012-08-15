#ifndef			CLIST_H
#define			CLIST_H

#include		<stddef.h>

typedef	struct CLink	CLink;
typedef	struct CList	CList;

struct			CList
{
  CLink*		begin;
  CLink*		end;
  size_t		size;
  void			(*des)();
};

struct			CLink
{
  CList*		list;
  CLink*		prev;
  CLink*		next;
  void*			data;
};

/* CLink* getters */
CList*			CList_list(CLink const*);
CLink*			CList_prev(CLink const*);
CLink*			CList_next(CLink const*);
void*			CList_data(CLink const*);

/* CList* getters */
CLink*			CList_begin(CList const*);
CLink*			CList_end(CList const*);
size_t			CList_size(CList const*);
int			CList_empty(CList const*);

void			CList_clear(CList*);
CLink*			CList_erase(CLink*);
CLink*			CList_find_data(CList const*, void const* data);
unsigned		CList_find_n_destroy(CList*, void const* data);
void			CList_foreach(CList const*, void (*fun)());
void			CList_init(CList*, void (*des)());
CLink*			CList_pop_back(CList*);
CLink*			CList_pop_front(CList*);
CLink*			CList_push_back(CList*, void* data, size_t);
CLink*			CList_push_front(CList*, void* data, size_t);

#endif
