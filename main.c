#include <stdio.h>
#include <string.h>
#include <xdo.h>

int main()
{
    Window *list = NULL;
    xdo_t *my_xdo = xdo_new(NULL);
    xdo_search_t search;
    unsigned int nwindows;
    unsigned int i;

    memset(&search, 0, sizeof(xdo_search_t));

    /* setup search */
    search.require = SEARCH_ANY;
    search.max_depth = -1;
    search.searchmask |= (SEARCH_CLASSNAME | SEARCH_ONLYVISIBLE);
    search.only_visible = True;
    char *winname = "gedit";
    search.winclassname= winname;

    /* do search */
    xdo_search_windows(my_xdo,&search,&list,&nwindows);

    /* print results */
    printf("number of windows: %d\n", nwindows);
    unsigned char * name;
    int size;
    int type;
    for(int i=0; i<nwindows; i++ ){
        xdo_get_window_name(my_xdo,list[i],&name,&size,&type);
        printf("%d: %s\n",i, name);
    }
    //for( int i=0;i<no_windows;i++ ){
    //    xdo_type(p_xdo,windows[i],"Hello World",0);
    //}
    ////xdo_type(p_xdo,CURRENTWINDOW,"Hello World",0); // This does work.
    return 0;
}
