#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


char buf[512];

void
wc(int fd, char *name) {
  int i, n;
  int l, w, c, inword;

  l = w = c = 0;
  inword = 0;
  
  
  while((n = read(fd, buf, sizeof(buf))) > 0){

    for(i=0; i<n; i++){
      c++;
      if(buf[i] == '\n')
        l++;
      if(strchr(" \r\t\n\v", buf[i]))
        inword = 0;
      else if(!inword){
        w++;
        inword = 1;
      }
    }
  }

  if(n < 0){
    printf(1, "wc: read error\n");
    exit();
  }

  printf(1, "%d %d %d %s\n", l, w, c, name);
}

int main(int argc, char *argv[])
{
  int fd, i;

  printf(1, "In main: argc count is %d", argc);
//  if(argc < 1){
//    wc(0, "");
 //   exit();
//  }

if((argc == 1) | (argc==2))
{
    	printf(1,"\n File name missing only filename %s exists",argv[0]);

    	printf(1,"\n Creating and closing new file called Blank.txt ");		

    	printf(1,"\n");

    	fd=open("Blank.txt",O_CREATE);

	close(fd);

	printf(1,"\n Opening new file called Blank.txt in writeonly mode ");

    	fd=open("Blank.txt",O_WRONLY);

    	write(fd,"Is life hard on xv6", 20); 

    	close(fd);

    	fd=open("Blank.txt",0);

    	wc(fd,"");

    	close(fd);

    
    	exit();
  }

    
for(i = 1; i < argc; i++){

    	printf(1,"argv[%d]=%s",i,argv[i-1]);

	if((fd = open(argv[i], 0)) < 0)
	{

      		printf(1, "wc: cannot open %s\n", argv[i]);
      		exit();
    	}

    

    	wc(fd, argv[i]);
    	close(fd);
  }
  	exit();
}