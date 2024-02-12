//DEBUG OR RELEASE
#define DO_DEBUG


//Front declaration
//declare here, implement later






//Kernel entry point
__kernel void entry_point(__global int* sample)
{
    int myid = get_global_id(0);
    printf("test %d sample",sample[myid]);
    //Only functions are allowed

}






#ifndef DO_DEBUG
//Release Codes




#endif //DO_RELEASE



#ifdef DO_DEBUG
//Debug Codes





#endif //DO_DEBUG