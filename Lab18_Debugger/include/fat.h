int fat_getpartition(void);
void fat_listdirectory(void);
unsigned int fat_getcluster(char *fn);
char *fat_readfile(unsigned int cluster);