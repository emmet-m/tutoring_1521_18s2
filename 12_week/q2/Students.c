// Students.c ... implementation of Students datatype

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include "Students.h"

typedef struct _stu_rec {
	int   id;
	char  name[20];
	int   degree;
	float wam;
} sturec_t;

typedef struct _students {
    int    nstu;
    StuRec recs;
} students_t;

// build a collection of student records from a file descriptor
Students getStudents(int in)
{
    // INitialise counter and create temporary sturec struct
    int size = 0;
    struct _stu_rec tmpStu;
    // Count amount of sturecs in file specified by 'in'
    // until there's no more studetns to read.
    while (read(in, &tmpStu, sizeof(struct _stu_rec)) == sizeof(struct _stu_rec)){
        size++;
    }

    // Reset file offset to start
    lseek(in, 0, SEEK_SET);

    // malloc amount of student records required
    // inside a students struct
    struct _students * stus = malloc(sizeof(struct _students));
    stus->nstu = size;
    stus->recs = malloc(sizeof(struct _stu_rec)*size);

    // Fill in the sturecs inside the student struct
    int i = 0;
    read(in, stus->recs, size*sizeof(struct _stu_rec));

	return stus;  
}

// show a list of student records pointed to by ss
void showStudents(Students ss)
{
	assert(ss != NULL);
	for (int i = 0; i < ss->nstu; i++)
		showStuRec(&(ss->recs[i]));
}

// show one student record pointed to by s
void showStuRec(StuRec s)
{
	printf("%7d %s %4d %0.1f\n", s->id, s->name, s->degree, s->wam);
}
