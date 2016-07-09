void save_line(char *);
void finish_line();
void add_reg(char *);
void add_ident(char *);
void add_instr(char *);
void add_punct(char);
void add_num(int);
void fail(char *msg);

/* Current line number */
int lineno;
