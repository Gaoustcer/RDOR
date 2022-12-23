int file_size(char* filename);
// {  
//     FILE *fp=fopen(filename,"r");  
//     if(!fp) return -1;  
//     fseek(fp,0L,SEEK_END);  
//     int size=ftell(fp);  
//     fclose(fp);  
      
//     return size;  
// }  