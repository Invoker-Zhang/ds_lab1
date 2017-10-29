/*
   return 1 when string src are absolutely equal to des.
   Otherwise return 0.
*/
int StrEqu(char *src,char *des){
	if(!(src&&des))
		return -1;
	int i=0;
	while(src[i]&&des[i]){
		if(src[i]!=des[i])
			return 0;
		i++;
	}
	if(src[i]||des[i])
		return 0;
	else return 1;
}

