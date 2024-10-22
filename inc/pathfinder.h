#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"
#include <limits.h>
#include <sys/stat.h>  
#include <fcntl.h>    
#include <unistd.h>

// some structures for a program
typedef enum e_error {
    FILE_DOESNTEXIST,
    FILE_EMPTY,
    INVALID_FIRST_LINE,
    INVALID_CMD_ARGS,
    INVALID_LINE,
    INVALID_NUM_ISLANDS,
    MEMORY_ALLOCATION_ERROR,
    DUPLICATE_BRIDGE,
    SUM_OF_BRIDGES_TOO_BIG,
    MAX_BRIDGE_LENGTH_SUM
} t_error;

typedef struct s_file t_file;
typedef struct s_main t_main;
typedef struct s_island t_island;
typedef struct s_link t_link;
typedef struct s_path t_path;
typedef struct s_algorithm t_algorithm;

struct s_main {
    t_file *file;             
    t_island *islands;        
    t_algorithm *algorithm;  
    t_path *path; 
    bool is_freed;
    int count_island;         
};

struct s_island {
    int index;                
    char *name;               
    t_link *links;            
    t_path **paths;           
    t_island *next;         
};

struct s_link {
    int weight;               
    t_island *linked_island;  
    t_link *next;             
};

struct s_path {
    t_link *route;            
    int dist;                 
    bool is_shortest;        
    t_path *next;            
};

struct s_algorithm {
    t_island *start;          
    t_island *end;            
    int weight;
    bool is_freed;               
    t_island *start_remainder; 
};

struct s_file {
    int fd;                   
    char *name;               
    char *filearray;          
    char **array;             
};

typedef struct s_pair {
    char *island1;
    char *island2;
    int distance;
    struct s_pair *next;
} t_pair;


//main
int main(int argc, char *argv[]);

//additional
int mx_atoi(const char *str);
bool mx_isalpha(int c);
bool mx_isdigit(int c);
char *mx_itoa(int number);
void *mx_memalloc_zero(size_t size);
void mx_printallerr(t_error err, const char *s);
void mx_printerr(const char *s);
void mx_printstr(const char *s);
void mx_stderr(const char *message);
char *mx_strchr(const char *s, int c);
char *mx_strrchr(const char *s, int c);

//creating main and algorith and open file
t_algorithm *mx_create_algorithm(void);
t_main *mx_create_main(char *argv[]);
char **mx_open_file_to_array(char *file);
t_file *mx_open_file(char *argv[]);

//memory allocate
void mx_free_file(t_file *file);
void mx_free_main(t_main *main);
void mx_free_islands(t_island *islands);
void mx_free_algorithm(t_algorithm *algorithm);

//all file for pathfinder 
void mx_pathfinder_prepare(t_main *main);
void mx_pathfinder_algorithm(t_main *main);
void mx_pathfinder_parse(t_main *main);
void mx_pathfinder_prints(t_main *main);

//graph
void mx_graph_island_add(t_island **islands, t_island *new_island);
t_island *mx_graph_island_create(char *name);
t_island *mx_graph_island_get(t_island **islands, char *name);
void mx_graph_link_add(t_link **links, t_link *new_link);
t_link *mx_graph_link_create(t_island *linked_island);
void mx_graph_link_pop_back(t_link **links);
void mx_graph_link_push_back(t_link **links, t_link *link);
void mx_graph_link_set(t_link **links, t_island *linked_island, int weight);
t_path *mx_graph_path_create(t_link *route);
void mx_graph_path_push_back(t_path **paths, t_path *path);
void mx_graph_path_push_front(t_path **paths, t_path *path);

//val
bool mx_val_checker(t_main *main);
bool mx_check_duplicate_directions(t_main *main);
bool mx_val_check_duplicate_bridges(char **array);
bool mx_val_check_delim(char **array);
bool mx_val_check_island_one_isalpha(char **array);
bool mx_val_check_number(char **array);
bool mx_val_check_end_line(char *array);
bool mx_val_file_empty(t_main *main);
bool mx_val_file_doesntexist(t_main *main);
bool mx_val_first_line(t_main *main);
bool mx_val_check_island_two_isalpha(char **array);
bool mx_val_sum_of_bridges(t_path *path);
bool mx_val_check_weight(int i, int weight);
bool mx_val_cmd_args(int argc);
bool mx_val_check_duplicate_bridges(char **array);
bool mx_val_num_islands(t_main *main);

#endif
