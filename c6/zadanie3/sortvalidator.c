int isValidSort(int *original,int *sorted,int size)
{
	/*check if sorted is really sorted*/
	for(int i=0;i<size-1;++i)
	{
		if(sorted[i]>sorted[i+1])
			return 0;
	}

	/*check if original is a permutation of sorted*/
	int size2=size;
	for(int i=0;i<size;++i)
	{
		int cur=sorted[i];
		int found=0;
		for(int j=0;j<size2;++j)
		{
			if(original[j]==cur)
			{
				found=1;
				int tmp=original[j];
				original[j]=original[size2-1];
				original[size2-1]=tmp;
				--size2;
				break;
			}
		}
		if(found==0)
			return 0;		
	}
	return 1;
}