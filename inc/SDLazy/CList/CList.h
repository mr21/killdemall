#ifndef			CLIST_H
# define		CLIST_H

typedef	struct CLink	CLink;
typedef	struct CList	CList;

struct			CLink
{
  CList*		list;
  CLink*		prev;
  CLink*		next;
  void*			data;
};

struct			CList
{
  CLink*		first;
  CLink*		last;
  unsigned		size;
  void			(*des)();
};

CLink*			CList_begin(CList*);
void			CList_clear(CList*);
int			CList_empty(CList*);
CLink*			CList_end(CList*);
CLink*			CList_erase(CLink*);
CLink*			CList_find_data(CList*, void* data);
unsigned		CList_find_n_destroy(CList*, void* data);
void			CList_foreach(CList*, void (*fun)());
void			CList_init(CList*, void (*des)());
CLink*			CList_pop_back(CList*);
CLink*			CList_pop_front(CList*);
CLink*			CList_push_back(CList*, void* data);
CLink*			CList_push_front(CList*, void* data);
unsigned		CList_size(CList*);

#endif
