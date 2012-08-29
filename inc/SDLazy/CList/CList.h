#ifndef			CLIST_H
#define			CLIST_H

#include		<stddef.h>

/* ForEach's value */
enum
{
  CLIST_CONTINUE,  /* Une maniere de ne rien faire  */
  CLIST_BREAK,     /* On stoppe la boucle           */
  CLIST_ERASE,     /* On supprime le maillon actuel */
  CLIST_ERASE_STOP /* On supprime et on s'arrete    */
};

typedef	struct CLink	CLink;
typedef	struct CList	CList;

struct			CLink
{
  CLink*		prev;
  CLink*		next;
  void			(*free)();
  void*			data; /* "data" doit TOUJOURS etre en dernier! */
};

struct			CList
{
  CLink*		begin;
  CLink*		end;
  size_t		size;
};

/* Init & destro */
void			CList_init (CList*);
void			CList_clear(CList*);

/* CLink* [gs]etters */
CLink*			CLink_prev  (CLink const*, size_t);
CLink*			CLink_next  (CLink const*, size_t);
void*			CLink_data  (CLink const*);
void			(*CLink_free(CLink const*))();

/* CList* [gs]etters */
CLink*			CList_begin(CList const*);
CLink*			CList_end  (CList const*);
size_t			CList_size (CList const*);
int			CList_empty(CList const*);
CLink*			CList_prev (CList const*, size_t);
CLink*			CList_next (CList const*, size_t);

/* Add */
CLink*			CList_push_back (CList*, void* data, size_t, void (*destr)());
CLink*			CList_push_front(CList*, void* data, size_t, void (*destr)());

/* Delete */
CLink*			CList_erase    (CList*, CLink*);
CLink*			CList_pop_back (CList*);
CLink*			CList_pop_front(CList*);

/* Treatement */
void			CList_foreach(CList*, int (*f)());

/* Find...            */
/*     ...by pointer  */
CLink*			CList_pfind_back  (CList const*, void const*);
CLink*			CList_pfind_front (CList const*, void const*);
CLink*			CList_pfind_after (CLink const*, void const*);
CLink*			CList_pfind_before(CLink const*, void const*);
/*     ...by function */
CLink*			CList_ffind_back  (CList const*, int (*f)());
CLink*			CList_ffind_front (CList const*, int (*f)());
CLink*			CList_ffind_after (CLink const*, int (*f)());
CLink*			CList_ffind_before(CLink const*, int (*f)());

/* Merge */
CList*			CList_merge_back  (CList* li, CList* la);
CList*			CList_merge_front (CList* li, CList* la);
CList*			CList_merge_after (CList* li, CLink*, CList* la);
CList*			CList_merge_before(CList* li, CLink*, CList* la);

/* Cut */
CList*			CList_cut      (CList*, CLink*, CLink*);
CList*			CList_cut_back (CList*, CLink*);
CList*			CList_cut_front(CList*, CLink*);

/* Move !!TODO!! */
CList*			CList_move_back  (CList* li, CLink* a, CLink* b, CList* la);
CList*			CList_move_front (CList* li, CLink* a, CLink* b, CList* la);
CList*			CList_move_after (CList* li, CLink* a, CLink* b, CList* la, CLink* c);
CList*			CList_move_before(CList* li, CLink* a, CLink* b, CList* la, CLink* c);

#endif
