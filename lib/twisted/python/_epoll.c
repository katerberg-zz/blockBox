/* Generated by Pyrex 0.9.4.1 on Sun Oct 15 15:04:09 2006 */

#define PY_SSIZE_T_CLEAN
#include "Python.h"
#include "structmember.h"
#ifndef PY_LONG_LONG
  #define PY_LONG_LONG LONG_LONG
#endif
#if PY_VERSION_HEX < 0x02050000
  typedef int Py_ssize_t;
  #define PY_SSIZE_T_MAX INT_MAX
  #define PY_SSIZE_T_MIN INT_MIN
  #define PyInt_FromSsize_t(z) PyInt_FromLong(z)
  #define PyInt_AsSsize_t(o)   PyInt_AsLong(o)
#endif
#ifdef __cplusplus
#define __PYX_EXTERN_C extern "C"
#else
#define __PYX_EXTERN_C extern
#endif
__PYX_EXTERN_C double pow(double, double);
#include "stdio.h"
#include "errno.h"
#include "string.h"
#include "stdint.h"
#include "sys/epoll.h"


typedef struct {const char *s; const void **p;} __Pyx_CApiTabEntry; /*proto*/
typedef struct {PyObject **p; char *s;} __Pyx_InternTabEntry; /*proto*/
typedef struct {PyObject **p; char *s; long n;} __Pyx_StringTabEntry; /*proto*/
static PyObject *__Pyx_UnpackItem(PyObject *, Py_ssize_t); /*proto*/
static int __Pyx_EndUnpack(PyObject *, Py_ssize_t); /*proto*/
static int __Pyx_PrintItem(PyObject *); /*proto*/
static int __Pyx_PrintNewline(void); /*proto*/
static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb); /*proto*/
static void __Pyx_ReRaise(void); /*proto*/
static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list); /*proto*/
static PyObject *__Pyx_GetExcValue(void); /*proto*/
static int __Pyx_ArgTypeTest(PyObject *obj, PyTypeObject *type, int none_allowed, char *name); /*proto*/
static int __Pyx_TypeTest(PyObject *obj, PyTypeObject *type); /*proto*/
static int __Pyx_GetStarArgs(PyObject **args, PyObject **kwds, char *kwd_list[], Py_ssize_t nargs, PyObject **args2, PyObject **kwds2); /*proto*/
static void __Pyx_WriteUnraisable(char *name); /*proto*/
static void __Pyx_AddTraceback(char *funcname); /*proto*/
static PyTypeObject *__Pyx_ImportType(char *module_name, char *class_name, long size);  /*proto*/
static int __Pyx_SetVtable(PyObject *dict, void *vtable); /*proto*/
static int __Pyx_GetVtable(PyObject *dict, void *vtabptr); /*proto*/
static PyObject *__Pyx_CreateClass(PyObject *bases, PyObject *dict, PyObject *name, char *modname); /*proto*/
static int __Pyx_InternStrings(__Pyx_InternTabEntry *t); /*proto*/
static int __Pyx_InitStrings(__Pyx_StringTabEntry *t); /*proto*/
static int __Pyx_InitCApi(PyObject *module); /*proto*/
static int __Pyx_ImportModuleCApi(__Pyx_CApiTabEntry *t); /*proto*/
static PyObject *__Pyx_GetName(PyObject *dict, PyObject *name); /*proto*/

static PyObject *__pyx_m;
static PyObject *__pyx_b;
static int __pyx_lineno;
static char *__pyx_filename;
static char **__pyx_f;

static char __pyx_mdoc[] = "\nInterface to epoll I/O event notification facility.\n";

/* Declarations from _epoll */


struct __pyx_obj_6_epoll_epoll {
  PyObject_HEAD
  int fd;
  int initialized;
};

static PyTypeObject *__pyx_ptype_6_epoll_epoll = 0;

/* Implementation of _epoll */

static PyObject *__pyx_n_CTL_ADD;
static PyObject *__pyx_n_CTL_DEL;
static PyObject *__pyx_n_CTL_MOD;
static PyObject *__pyx_n_IN;
static PyObject *__pyx_n_OUT;
static PyObject *__pyx_n_PRI;
static PyObject *__pyx_n_ERR;
static PyObject *__pyx_n_HUP;
static PyObject *__pyx_n_ET;
static PyObject *__pyx_n_RDNORM;
static PyObject *__pyx_n_RDBAND;
static PyObject *__pyx_n_WRNORM;
static PyObject *__pyx_n_WRBAND;
static PyObject *__pyx_n_MSG;

static PyObject *__pyx_n_IOError;

static int __pyx_f_6_epoll_5epoll___init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static int __pyx_f_6_epoll_5epoll___init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  int __pyx_v_size;
  int __pyx_r;
  int __pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  PyObject *__pyx_5 = 0;
  static char *__pyx_argnames[] = {"size",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "i", __pyx_argnames, &__pyx_v_size)) return -1;
  Py_INCREF(__pyx_v_self);

  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":77 */
  ((struct __pyx_obj_6_epoll_epoll *)__pyx_v_self)->fd = epoll_create(__pyx_v_size);

  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":78 */
  __pyx_1 = (((struct __pyx_obj_6_epoll_epoll *)__pyx_v_self)->fd == (-1));
  if (__pyx_1) {

	/* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":79 */
	__pyx_2 = __Pyx_GetName(__pyx_b, __pyx_n_IOError); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 79; goto __pyx_L1;}
	__pyx_3 = PyInt_FromLong(errno); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 79; goto __pyx_L1;}
	__pyx_4 = PyString_FromString(strerror(errno)); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 79; goto __pyx_L1;}
	__pyx_5 = PyTuple_New(2); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 79; goto __pyx_L1;}
	PyTuple_SET_ITEM(__pyx_5, 0, __pyx_3);
	PyTuple_SET_ITEM(__pyx_5, 1, __pyx_4);
	__pyx_3 = 0;
	__pyx_4 = 0;
	__pyx_3 = PyObject_Call(__pyx_2, __pyx_5, 0); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 79; goto __pyx_L1;}
	Py_DECREF(__pyx_2); __pyx_2 = 0;
	Py_DECREF(__pyx_5); __pyx_5 = 0;
	__Pyx_Raise(__pyx_3, 0, 0);
	Py_DECREF(__pyx_3); __pyx_3 = 0;
	{__pyx_filename = __pyx_f[0]; __pyx_lineno = 79; goto __pyx_L1;}
	goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":80 */
  ((struct __pyx_obj_6_epoll_epoll *)__pyx_v_self)->initialized = 1;

  __pyx_r = 0;
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  Py_XDECREF(__pyx_5);
  __Pyx_AddTraceback("_epoll.epoll.__init__");
  __pyx_r = -1;
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static void __pyx_f_6_epoll_5epoll___dealloc__(PyObject *__pyx_v_self); /*proto*/
static void __pyx_f_6_epoll_5epoll___dealloc__(PyObject *__pyx_v_self) {
  int __pyx_1;
  Py_INCREF(__pyx_v_self);

  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":83 */
  __pyx_1 = ((struct __pyx_obj_6_epoll_epoll *)__pyx_v_self)->initialized;
  if (__pyx_1) {

	/* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":84 */
	close(((struct __pyx_obj_6_epoll_epoll *)__pyx_v_self)->fd);

	/* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":85 */
	((struct __pyx_obj_6_epoll_epoll *)__pyx_v_self)->initialized = 0;
	goto __pyx_L2;
  }
  __pyx_L2:;

  goto __pyx_L0;
  __pyx_L1:;
  __Pyx_AddTraceback("_epoll.epoll.__dealloc__");
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
}

static PyObject *__pyx_f_6_epoll_5epoll_close(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_6_epoll_5epoll_close[] = "\n		Close the epoll file descriptor.\n		";
static PyObject *__pyx_f_6_epoll_5epoll_close(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_r;
  int __pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  PyObject *__pyx_5 = 0;
  static char *__pyx_argnames[] = {0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) return 0;
  Py_INCREF(__pyx_v_self);

  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":91 */
  __pyx_1 = ((struct __pyx_obj_6_epoll_epoll *)__pyx_v_self)->initialized;
  if (__pyx_1) {

	/* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":92 */
	__pyx_1 = (close(((struct __pyx_obj_6_epoll_epoll *)__pyx_v_self)->fd) == (-1));
	if (__pyx_1) {

	  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":93 */
	  __pyx_2 = __Pyx_GetName(__pyx_b, __pyx_n_IOError); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 93; goto __pyx_L1;}
	  __pyx_3 = PyInt_FromLong(errno); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 93; goto __pyx_L1;}
	  __pyx_4 = PyString_FromString(strerror(errno)); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 93; goto __pyx_L1;}
	  __pyx_5 = PyTuple_New(2); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 93; goto __pyx_L1;}
	  PyTuple_SET_ITEM(__pyx_5, 0, __pyx_3);
	  PyTuple_SET_ITEM(__pyx_5, 1, __pyx_4);
	  __pyx_3 = 0;
	  __pyx_4 = 0;
	  __pyx_3 = PyObject_Call(__pyx_2, __pyx_5, 0); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 93; goto __pyx_L1;}
	  Py_DECREF(__pyx_2); __pyx_2 = 0;
	  Py_DECREF(__pyx_5); __pyx_5 = 0;
	  __Pyx_Raise(__pyx_3, 0, 0);
	  Py_DECREF(__pyx_3); __pyx_3 = 0;
	  {__pyx_filename = __pyx_f[0]; __pyx_lineno = 93; goto __pyx_L1;}
	  goto __pyx_L3;
	}
	__pyx_L3:;

	/* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":94 */
	((struct __pyx_obj_6_epoll_epoll *)__pyx_v_self)->initialized = 0;
	goto __pyx_L2;
  }
  __pyx_L2:;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  Py_XDECREF(__pyx_5);
  __Pyx_AddTraceback("_epoll.epoll.close");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_f_6_epoll_5epoll_fileno(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_6_epoll_5epoll_fileno[] = "\n		Return the epoll file descriptor number.\n		";
static PyObject *__pyx_f_6_epoll_5epoll_fileno(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  static char *__pyx_argnames[] = {0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "", __pyx_argnames)) return 0;
  Py_INCREF(__pyx_v_self);

  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":100 */
  __pyx_1 = PyInt_FromLong(((struct __pyx_obj_6_epoll_epoll *)__pyx_v_self)->fd); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 100; goto __pyx_L1;}
  __pyx_r = __pyx_1;
  __pyx_1 = 0;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  __Pyx_AddTraceback("_epoll.epoll.fileno");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_f_6_epoll_5epoll__control(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_6_epoll_5epoll__control[] = "\n		Modify the monitored state of a particular file descriptor.\n		\n		Wrap epoll_ctl(2).\n\n		@type op: C{int}\n		@param op: One of CTL_ADD, CTL_DEL, or CTL_MOD\n\n		@type fd: C{int}\n		@param fd: File descriptor to modify\n\n		@type events: C{int}\n		@param events: A bit set of IN, OUT, PRI, ERR, HUP, and ET.\n\n		@raise IOError: Raised if the underlying epoll_ctl() call fails.\n		";
static PyObject *__pyx_f_6_epoll_5epoll__control(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  int __pyx_v_op;
  int __pyx_v_fd;
  int __pyx_v_events;
  int __pyx_v_result;
  struct epoll_event __pyx_v_evt;
  PyObject *__pyx_r;
  int __pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  PyObject *__pyx_5 = 0;
  static char *__pyx_argnames[] = {"op","fd","events",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "iii", __pyx_argnames, &__pyx_v_op, &__pyx_v_fd, &__pyx_v_events)) return 0;
  Py_INCREF(__pyx_v_self);

  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":121 */
  __pyx_v_evt.events = __pyx_v_events;

  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":122 */
  __pyx_v_evt.data.fd = __pyx_v_fd;

  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":123 */
  __pyx_v_result = epoll_ctl(((struct __pyx_obj_6_epoll_epoll *)__pyx_v_self)->fd,__pyx_v_op,__pyx_v_fd,(&__pyx_v_evt));

  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":124 */
  __pyx_1 = (__pyx_v_result == (-1));
  if (__pyx_1) {

	/* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":125 */
	__pyx_2 = __Pyx_GetName(__pyx_b, __pyx_n_IOError); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 125; goto __pyx_L1;}
	__pyx_3 = PyInt_FromLong(errno); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 125; goto __pyx_L1;}
	__pyx_4 = PyString_FromString(strerror(errno)); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 125; goto __pyx_L1;}
	__pyx_5 = PyTuple_New(2); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 125; goto __pyx_L1;}
	PyTuple_SET_ITEM(__pyx_5, 0, __pyx_3);
	PyTuple_SET_ITEM(__pyx_5, 1, __pyx_4);
	__pyx_3 = 0;
	__pyx_4 = 0;
	__pyx_3 = PyObject_Call(__pyx_2, __pyx_5, 0); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 125; goto __pyx_L1;}
	Py_DECREF(__pyx_2); __pyx_2 = 0;
	Py_DECREF(__pyx_5); __pyx_5 = 0;
	__Pyx_Raise(__pyx_3, 0, 0);
	Py_DECREF(__pyx_3); __pyx_3 = 0;
	{__pyx_filename = __pyx_f[0]; __pyx_lineno = 125; goto __pyx_L1;}
	goto __pyx_L2;
  }
  __pyx_L2:;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  Py_XDECREF(__pyx_5);
  __Pyx_AddTraceback("_epoll.epoll._control");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static PyObject *__pyx_n_append;

static PyObject *__pyx_f_6_epoll_5epoll_wait(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_6_epoll_5epoll_wait[] = "\n		Wait for an I/O event, wrap epoll_wait(2).\n\n		@type maxevents: C{int}\n		@param maxevents: Maximum number of events returned.\n\n		@type timeout: C{int}\n		@param timeout: Maximum time waiting for events. 0 makes it return\n			immediately whereas -1 makes it wait indefinitely.\n		\n		@raise IOError: Raised if the underlying epoll_wait() call fails.\n		";
static PyObject *__pyx_f_6_epoll_5epoll_wait(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  unsigned int __pyx_v_maxevents;
  int __pyx_v_timeout;
  struct epoll_event (*__pyx_v_events);
  int __pyx_v_result;
  int __pyx_v_nbytes;
  int __pyx_v_fd;
  PyThreadState (*__pyx_v__save);
  PyObject *__pyx_v_results;
  PyObject *__pyx_v_i;
  PyObject *__pyx_r;
  int __pyx_1;
  PyObject *__pyx_2 = 0;
  PyObject *__pyx_3 = 0;
  PyObject *__pyx_4 = 0;
  PyObject *__pyx_5 = 0;
  long __pyx_6;
  Py_ssize_t __pyx_7;
  static char *__pyx_argnames[] = {"maxevents","timeout",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "Ii", __pyx_argnames, &__pyx_v_maxevents, &__pyx_v_timeout)) return 0;
  Py_INCREF(__pyx_v_self);
  __pyx_v_results = Py_None; Py_INCREF(Py_None);
  __pyx_v_i = Py_None; Py_INCREF(Py_None);

  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":146 */
  __pyx_v_nbytes = ((sizeof(struct epoll_event )) * __pyx_v_maxevents);

  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":147 */
  __pyx_v_events = ((struct epoll_event (*))malloc(__pyx_v_nbytes));

  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":148 */
  memset(__pyx_v_events,0,__pyx_v_nbytes);

  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":149 */
  /*try:*/ {

	/* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":150 */
	__pyx_v_fd = ((struct __pyx_obj_6_epoll_epoll *)__pyx_v_self)->fd;

	/* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":152 */
	__pyx_v__save = PyEval_SaveThread();

	/* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":153 */
	__pyx_v_result = epoll_wait(__pyx_v_fd,__pyx_v_events,__pyx_v_maxevents,__pyx_v_timeout);

	/* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":154 */
	PyEval_RestoreThread(__pyx_v__save);

	/* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":156 */
	__pyx_1 = (__pyx_v_result == (-1));
	if (__pyx_1) {

	  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":157 */
	  __pyx_2 = __Pyx_GetName(__pyx_b, __pyx_n_IOError); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 157; goto __pyx_L3;}
	  __pyx_3 = PyInt_FromLong(errno); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 157; goto __pyx_L3;}
	  __pyx_4 = PyString_FromString(strerror(errno)); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 157; goto __pyx_L3;}
	  __pyx_5 = PyTuple_New(2); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 157; goto __pyx_L3;}
	  PyTuple_SET_ITEM(__pyx_5, 0, __pyx_3);
	  PyTuple_SET_ITEM(__pyx_5, 1, __pyx_4);
	  __pyx_3 = 0;
	  __pyx_4 = 0;
	  __pyx_3 = PyObject_Call(__pyx_2, __pyx_5, 0); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 157; goto __pyx_L3;}
	  Py_DECREF(__pyx_2); __pyx_2 = 0;
	  Py_DECREF(__pyx_5); __pyx_5 = 0;
	  __Pyx_Raise(__pyx_3, 0, 0);
	  Py_DECREF(__pyx_3); __pyx_3 = 0;
	  {__pyx_filename = __pyx_f[0]; __pyx_lineno = 157; goto __pyx_L3;}
	  goto __pyx_L5;
	}
	__pyx_L5:;

	/* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":158 */
	__pyx_4 = PyList_New(0); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 158; goto __pyx_L3;}
	Py_DECREF(__pyx_v_results);
	__pyx_v_results = __pyx_4;
	__pyx_4 = 0;

	/* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":159 */
	for (__pyx_6 = 0; __pyx_6 < __pyx_v_result; ++__pyx_6) {
	  __pyx_2 = PyInt_FromLong(__pyx_6); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 159; goto __pyx_L3;}
	  Py_DECREF(__pyx_v_i);
	  __pyx_v_i = __pyx_2;
	  __pyx_2 = 0;

	  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":160 */
	  __pyx_5 = PyObject_GetAttr(__pyx_v_results, __pyx_n_append); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 160; goto __pyx_L3;}
	  __pyx_7 = PyInt_AsSsize_t(__pyx_v_i); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 160; goto __pyx_L3;}
	  __pyx_3 = PyInt_FromLong((__pyx_v_events[__pyx_7]).data.fd); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 160; goto __pyx_L3;}
	  __pyx_7 = PyInt_AsSsize_t(__pyx_v_i); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 160; goto __pyx_L3;}
	  __pyx_4 = PyInt_FromLong(((int )(__pyx_v_events[__pyx_7]).events)); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 160; goto __pyx_L3;}
	  __pyx_2 = PyTuple_New(2); if (!__pyx_2) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 160; goto __pyx_L3;}
	  PyTuple_SET_ITEM(__pyx_2, 0, __pyx_3);
	  PyTuple_SET_ITEM(__pyx_2, 1, __pyx_4);
	  __pyx_3 = 0;
	  __pyx_4 = 0;
	  __pyx_3 = PyTuple_New(1); if (!__pyx_3) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 160; goto __pyx_L3;}
	  PyTuple_SET_ITEM(__pyx_3, 0, __pyx_2);
	  __pyx_2 = 0;
	  __pyx_4 = PyObject_Call(__pyx_5, __pyx_3, 0); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 160; goto __pyx_L3;}
	  Py_DECREF(__pyx_5); __pyx_5 = 0;
	  Py_DECREF(__pyx_3); __pyx_3 = 0;
	  Py_DECREF(__pyx_4); __pyx_4 = 0;
	  __pyx_L6:;
	}
	__pyx_L7:;

	/* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":161 */
	Py_INCREF(__pyx_v_results);
	__pyx_r = __pyx_v_results;
	goto __pyx_L2;
  }
  /*finally:*/ {
	int __pyx_why;
	__pyx_why = 0; goto __pyx_L4;
	__pyx_L2: __pyx_why = 3; goto __pyx_L4;
	__pyx_L3: {
	  __pyx_why = 4;
	  Py_XDECREF(__pyx_2); __pyx_2 = 0;
	  Py_XDECREF(__pyx_5); __pyx_5 = 0;
	  Py_XDECREF(__pyx_3); __pyx_3 = 0;
	  Py_XDECREF(__pyx_4); __pyx_4 = 0;
	  PyErr_Fetch(&__pyx_2, &__pyx_5, &__pyx_3);
	  __pyx_1 = __pyx_lineno;
	  goto __pyx_L4;
	}
	__pyx_L4:;

	/* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":163 */
	free(__pyx_v_events);
	switch (__pyx_why) {
	  case 3: goto __pyx_L0;
	  case 4: {
		PyErr_Restore(__pyx_2, __pyx_5, __pyx_3);
		__pyx_lineno = __pyx_1;
		__pyx_2 = 0;
		__pyx_5 = 0;
		__pyx_3 = 0;
		goto __pyx_L1;
	  }
	}
  }

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_2);
  Py_XDECREF(__pyx_3);
  Py_XDECREF(__pyx_4);
  Py_XDECREF(__pyx_5);
  __Pyx_AddTraceback("_epoll.epoll.wait");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_results);
  Py_DECREF(__pyx_v_i);
  Py_DECREF(__pyx_v_self);
  return __pyx_r;
}

static __Pyx_InternTabEntry __pyx_intern_tab[] = {
  {&__pyx_n_CTL_ADD, "CTL_ADD"},
  {&__pyx_n_CTL_DEL, "CTL_DEL"},
  {&__pyx_n_CTL_MOD, "CTL_MOD"},
  {&__pyx_n_ERR, "ERR"},
  {&__pyx_n_ET, "ET"},
  {&__pyx_n_HUP, "HUP"},
  {&__pyx_n_IN, "IN"},
  {&__pyx_n_IOError, "IOError"},
  {&__pyx_n_MSG, "MSG"},
  {&__pyx_n_OUT, "OUT"},
  {&__pyx_n_PRI, "PRI"},
  {&__pyx_n_RDBAND, "RDBAND"},
  {&__pyx_n_RDNORM, "RDNORM"},
  {&__pyx_n_WRBAND, "WRBAND"},
  {&__pyx_n_WRNORM, "WRNORM"},
  {&__pyx_n_append, "append"},
  {0, 0}
};

static PyObject *__pyx_tp_new_6_epoll_epoll(PyTypeObject *t, PyObject *a, PyObject *k) {
  PyObject *o = (*t->tp_alloc)(t, 0);
  struct __pyx_obj_6_epoll_epoll *p = (struct __pyx_obj_6_epoll_epoll *)o;
  return o;
}

static void __pyx_tp_dealloc_6_epoll_epoll(PyObject *o) {
  struct __pyx_obj_6_epoll_epoll *p = (struct __pyx_obj_6_epoll_epoll *)o;
  {
	PyObject *etype, *eval, *etb;
	PyErr_Fetch(&etype, &eval, &etb);
	++o->ob_refcnt;
	__pyx_f_6_epoll_5epoll___dealloc__(o);
	if (PyErr_Occurred()) PyErr_WriteUnraisable(o);
	--o->ob_refcnt;
	PyErr_Restore(etype, eval, etb);
  }
  (*o->ob_type->tp_free)(o);
}

static int __pyx_tp_traverse_6_epoll_epoll(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_6_epoll_epoll *p = (struct __pyx_obj_6_epoll_epoll *)o;
  return 0;
}

static int __pyx_tp_clear_6_epoll_epoll(PyObject *o) {
  struct __pyx_obj_6_epoll_epoll *p = (struct __pyx_obj_6_epoll_epoll *)o;
  return 0;
}

static struct PyMethodDef __pyx_methods_6_epoll_epoll[] = {
  {"close", (PyCFunction)__pyx_f_6_epoll_5epoll_close, METH_VARARGS|METH_KEYWORDS, __pyx_doc_6_epoll_5epoll_close},
  {"fileno", (PyCFunction)__pyx_f_6_epoll_5epoll_fileno, METH_VARARGS|METH_KEYWORDS, __pyx_doc_6_epoll_5epoll_fileno},
  {"_control", (PyCFunction)__pyx_f_6_epoll_5epoll__control, METH_VARARGS|METH_KEYWORDS, __pyx_doc_6_epoll_5epoll__control},
  {"wait", (PyCFunction)__pyx_f_6_epoll_5epoll_wait, METH_VARARGS|METH_KEYWORDS, __pyx_doc_6_epoll_5epoll_wait},
  {0, 0, 0, 0}
};

static PyNumberMethods __pyx_tp_as_number_epoll = {
  0, /*nb_add*/
  0, /*nb_subtract*/
  0, /*nb_multiply*/
  0, /*nb_divide*/
  0, /*nb_remainder*/
  0, /*nb_divmod*/
  0, /*nb_power*/
  0, /*nb_negative*/
  0, /*nb_positive*/
  0, /*nb_absolute*/
  0, /*nb_nonzero*/
  0, /*nb_invert*/
  0, /*nb_lshift*/
  0, /*nb_rshift*/
  0, /*nb_and*/
  0, /*nb_xor*/
  0, /*nb_or*/
  0, /*nb_coerce*/
  0, /*nb_int*/
  0, /*nb_long*/
  0, /*nb_float*/
  0, /*nb_oct*/
  0, /*nb_hex*/
  0, /*nb_inplace_add*/
  0, /*nb_inplace_subtract*/
  0, /*nb_inplace_multiply*/
  0, /*nb_inplace_divide*/
  0, /*nb_inplace_remainder*/
  0, /*nb_inplace_power*/
  0, /*nb_inplace_lshift*/
  0, /*nb_inplace_rshift*/
  0, /*nb_inplace_and*/
  0, /*nb_inplace_xor*/
  0, /*nb_inplace_or*/
  0, /*nb_floor_divide*/
  0, /*nb_true_divide*/
  0, /*nb_inplace_floor_divide*/
  0, /*nb_inplace_true_divide*/
};

static PySequenceMethods __pyx_tp_as_sequence_epoll = {
  0, /*sq_length*/
  0, /*sq_concat*/
  0, /*sq_repeat*/
  0, /*sq_item*/
  0, /*sq_slice*/
  0, /*sq_ass_item*/
  0, /*sq_ass_slice*/
  0, /*sq_contains*/
  0, /*sq_inplace_concat*/
  0, /*sq_inplace_repeat*/
};

static PyMappingMethods __pyx_tp_as_mapping_epoll = {
  0, /*mp_length*/
  0, /*mp_subscript*/
  0, /*mp_ass_subscript*/
};

static PyBufferProcs __pyx_tp_as_buffer_epoll = {
  0, /*bf_getreadbuffer*/
  0, /*bf_getwritebuffer*/
  0, /*bf_getsegcount*/
  0, /*bf_getcharbuffer*/
};

PyTypeObject __pyx_type_6_epoll_epoll = {
  PyObject_HEAD_INIT(0)
  0, /*ob_size*/
  "_epoll.epoll", /*tp_name*/
  sizeof(struct __pyx_obj_6_epoll_epoll), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_6_epoll_epoll, /*tp_dealloc*/
  0, /*tp_print*/
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  0, /*tp_compare*/
  0, /*tp_repr*/
  &__pyx_tp_as_number_epoll, /*tp_as_number*/
  &__pyx_tp_as_sequence_epoll, /*tp_as_sequence*/
  &__pyx_tp_as_mapping_epoll, /*tp_as_mapping*/
  0, /*tp_hash*/
  0, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  &__pyx_tp_as_buffer_epoll, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_HAVE_GC, /*tp_flags*/
  "\n	Represent a set of file descriptors being monitored for events.\n	", /*tp_doc*/
  __pyx_tp_traverse_6_epoll_epoll, /*tp_traverse*/
  __pyx_tp_clear_6_epoll_epoll, /*tp_clear*/
  0, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  __pyx_methods_6_epoll_epoll, /*tp_methods*/
  0, /*tp_members*/
  0, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  __pyx_f_6_epoll_5epoll___init__, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_6_epoll_epoll, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
};

static struct PyMethodDef __pyx_methods[] = {
  {0, 0, 0, 0}
};

static void __pyx_init_filenames(void); /*proto*/

PyMODINIT_FUNC init_epoll(void); /*proto*/
PyMODINIT_FUNC init_epoll(void) {
  PyObject *__pyx_1 = 0;
  __pyx_init_filenames();
  __pyx_m = Py_InitModule4("_epoll", __pyx_methods, __pyx_mdoc, 0, PYTHON_API_VERSION);
  if (!__pyx_m) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 4; goto __pyx_L1;};
  __pyx_b = PyImport_AddModule("__builtin__");
  if (!__pyx_b) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 4; goto __pyx_L1;};
  if (PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 4; goto __pyx_L1;};
  if (__Pyx_InternStrings(__pyx_intern_tab) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 4; goto __pyx_L1;};
  if (PyType_Ready(&__pyx_type_6_epoll_epoll) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 68; goto __pyx_L1;}
  if (PyObject_SetAttrString(__pyx_m, "epoll", (PyObject *)&__pyx_type_6_epoll_epoll) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 68; goto __pyx_L1;}
  __pyx_ptype_6_epoll_epoll = &__pyx_type_6_epoll_epoll;

  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":165 */
  __pyx_1 = PyInt_FromLong(EPOLL_CTL_ADD); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 165; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_CTL_ADD, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 165; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":166 */
  __pyx_1 = PyInt_FromLong(EPOLL_CTL_DEL); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 166; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_CTL_DEL, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 166; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":167 */
  __pyx_1 = PyInt_FromLong(EPOLL_CTL_MOD); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 167; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_CTL_MOD, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 167; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":169 */
  __pyx_1 = PyInt_FromLong(EPOLLIN); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 169; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_IN, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 169; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":170 */
  __pyx_1 = PyInt_FromLong(EPOLLOUT); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 170; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_OUT, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 170; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":171 */
  __pyx_1 = PyInt_FromLong(EPOLLPRI); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 171; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_PRI, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 171; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":172 */
  __pyx_1 = PyInt_FromLong(EPOLLERR); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 172; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_ERR, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 172; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":173 */
  __pyx_1 = PyInt_FromLong(EPOLLHUP); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 173; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_HUP, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 173; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":174 */
  __pyx_1 = PyInt_FromLong(EPOLLET); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 174; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_ET, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 174; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":176 */
  __pyx_1 = PyInt_FromLong(EPOLLRDNORM); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 176; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_RDNORM, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 176; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":177 */
  __pyx_1 = PyInt_FromLong(EPOLLRDBAND); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 177; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_RDBAND, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 177; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":178 */
  __pyx_1 = PyInt_FromLong(EPOLLWRNORM); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 178; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_WRNORM, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 178; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":179 */
  __pyx_1 = PyInt_FromLong(EPOLLWRBAND); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 179; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_WRBAND, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 179; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;

  /* "/home/exarkun/Projects/Twisted/branches/epollreactor-1953-2/twisted/python/_epoll.pyx":180 */
  __pyx_1 = PyInt_FromLong(EPOLLMSG); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 180; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_MSG, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 180; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  return;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  __Pyx_AddTraceback("_epoll");
}

static char *__pyx_filenames[] = {
  "_epoll.pyx",
};

/* Runtime support code */

static void __pyx_init_filenames(void) {
  __pyx_f = __pyx_filenames;
}

static PyObject *__Pyx_GetName(PyObject *dict, PyObject *name) {
	PyObject *result;
	result = PyObject_GetAttr(dict, name);
	if (!result)
		PyErr_SetObject(PyExc_NameError, name);
	return result;
}

static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb) {
	Py_XINCREF(type);
	Py_XINCREF(value);
	Py_XINCREF(tb);
	/* First, check the traceback argument, replacing None with NULL. */
	if (tb == Py_None) {
		Py_DECREF(tb);
		tb = 0;
	}
	else if (tb != NULL && !PyTraceBack_Check(tb)) {
		PyErr_SetString(PyExc_TypeError,
			"raise: arg 3 must be a traceback or None");
		goto raise_error;
	}
	/* Next, replace a missing value with None */
	if (value == NULL) {
		value = Py_None;
		Py_INCREF(value);
	}
	/* Next, repeatedly, replace a tuple exception with its first item */
	while (PyTuple_Check(type) && PyTuple_Size(type) > 0) {
		PyObject *tmp = type;
		type = PyTuple_GET_ITEM(type, 0);
		Py_INCREF(type);
		Py_DECREF(tmp);
	}
	if (PyString_CheckExact(type)) {
		/* Raising builtin string is deprecated but still allowed --
		 * do nothing.  Raising an instance of a new-style str
		 * subclass is right out. */
		if (PyErr_Warn(PyExc_DeprecationWarning,
				   "raising a string exception is deprecated"))
				goto raise_error;
	}
	else if (PyType_Check(type) || PyClass_Check(type))
		; /* PyErr_NormalizeException(&type, &value, &tb); */
	else if (PyInstance_Check(type)) {
		/* Raising an instance.  The value should be a dummy. */
		if (value != Py_None) {
			PyErr_SetString(PyExc_TypeError,
			  "instance exception may not have a separate value");
			goto raise_error;
		}
		else {
			/* Normalize to raise <class>, <instance> */
			Py_DECREF(value);
			value = type;
			type = (PyObject*) ((PyInstanceObject*)type)->in_class;
			Py_INCREF(type);
		}
	}
	else if (PyType_IsSubtype(type->ob_type, (PyTypeObject*)PyExc_Exception)) {
		/* Raising a new-style object (in Py2.5).
		   The value should be a dummy. */
		if (value != Py_None) {
				PyErr_SetString(PyExc_TypeError,
				  "instance exception may not have a separate value");
				goto raise_error;
		}
		else {
				/* Normalize to raise <class>, <instance> */
				Py_DECREF(value);
				value = type;
				type = (PyObject*) type->ob_type;
				Py_INCREF(type);
		}
	}
	else {
		/* Not something you can raise.  You get an exception
		   anyway, just not what you specified :-) */
		PyErr_Format(PyExc_TypeError,
					 "exceptions must be classes, instances, or "
					 "strings (deprecated), not %s",
					 type->ob_type->tp_name);
		goto raise_error;
	}
	PyErr_Restore(type, value, tb);
	return;
raise_error:
	Py_XDECREF(value);
	Py_XDECREF(type);
	Py_XDECREF(tb);
	return;
}

static int __Pyx_InternStrings(__Pyx_InternTabEntry *t) {
	while (t->p) {
		*t->p = PyString_InternFromString(t->s);
		if (!*t->p)
			return -1;
		++t;
	}
	return 0;
}

#include "compile.h"
#include "frameobject.h"
#include "traceback.h"

static void __Pyx_AddTraceback(char *funcname) {
	PyObject *py_srcfile = 0;
	PyObject *py_funcname = 0;
	PyObject *py_globals = 0;
	PyObject *empty_tuple = 0;
	PyObject *empty_string = 0;
	PyCodeObject *py_code = 0;
	PyFrameObject *py_frame = 0;
	
	py_srcfile = PyString_FromString(__pyx_filename);
	if (!py_srcfile) goto bad;
	py_funcname = PyString_FromString(funcname);
	if (!py_funcname) goto bad;
	py_globals = PyModule_GetDict(__pyx_m);
	if (!py_globals) goto bad;
	empty_tuple = PyTuple_New(0);
	if (!empty_tuple) goto bad;
	empty_string = PyString_FromString("");
	if (!empty_string) goto bad;
	py_code = PyCode_New(
		0,			/*int argcount,*/
		0,			/*int nlocals,*/
		0,			/*int stacksize,*/
		0,			/*int flags,*/
		empty_string, /*PyObject *code,*/
		empty_tuple,  /*PyObject *consts,*/
		empty_tuple,  /*PyObject *names,*/
		empty_tuple,  /*PyObject *varnames,*/
		empty_tuple,  /*PyObject *freevars,*/
		empty_tuple,  /*PyObject *cellvars,*/
		py_srcfile,   /*PyObject *filename,*/
		py_funcname,  /*PyObject *name,*/
		__pyx_lineno,   /*int firstlineno,*/
		empty_string  /*PyObject *lnotab*/
	);
	if (!py_code) goto bad;
	py_frame = PyFrame_New(
		PyThreadState_Get(), /*PyThreadState *tstate,*/
		py_code,			 /*PyCodeObject *code,*/
		py_globals,		  /*PyObject *globals,*/
		0					/*PyObject *locals*/
	);
	if (!py_frame) goto bad;
	py_frame->f_lineno = __pyx_lineno;
	PyTraceBack_Here(py_frame);
bad:
	Py_XDECREF(py_srcfile);
	Py_XDECREF(py_funcname);
	Py_XDECREF(empty_tuple);
	Py_XDECREF(empty_string);
	Py_XDECREF(py_code);
	Py_XDECREF(py_frame);
}
