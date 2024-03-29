#include "cl_global_custom.h"
#include <fstream>
#include <sstream>


Platform
clboost::get_platform()
{
	vector<Platform> pfvec;
	Platform::get(&pfvec);
	ASSERT_UEQ(pfvec.empty(), true);
	for (int i = 0; i < pfvec.size(); i++) {

		std::string pname;
		vector<Device> dvs;
		pfvec[i].getInfo(CL_PLATFORM_NAME, &pname);
		pfvec[i].getDevices(CL_DEVICE_TYPE_ALL, &dvs);
		for (int j = 0; j < dvs.size(); j++) {
			std::string dname;
			dvs[j].getInfo(CL_DEVICE_NAME, &dname);
		}
	}

	Platform pf=pfvec[2];
	return pf;
}

Device
clboost::get_gpu_device(const Platform& pf)
{
	vector<Device> dvs;
	pf.getDevices(CL_DEVICE_TYPE_GPU, &dvs);
	ASSERT_UEQ(dvs.empty(), true);
	Device dv = dvs[0];
	return dv;
}

Context
clboost::get_context(const Device& dev)
{
	return Context(dev);
}

CommandQueue
clboost::make_cq(const Context& ct, const Device& dev)
{
	return CommandQueue(ct, dev);
}
#ifndef NO_EMBEDDED_CL


Program
clboost::make_prog(const std::string& hardcoded_cl_code, const Context& ct, const Device& dev)
{
	Program pg(ct,hardcoded_cl_code);
	
	pg.build(dev);
	std::string err_message = pg.getBuildInfo<CL_PROGRAM_BUILD_LOG>(dev);
	ASSERT_EQ(err_message, "\n");
	return pg;
}
#endif  // !NO_EMBEDDED_CL
#ifdef NO_EMBEDDED_CL


Program
clboost::make_prog(const std::string& path, const Context& ct, const Device& dev)
{

	ASSERT_NO_STRING(path);
	std::ifstream fp;
	fp.open(path);
	ASSERT_EQ(fp.is_open(), true);
	std::stringstream ss;
	ss << fp.rdbuf();
	string source=ss.str();
	ASSERT_NO_STRING(source);
	
	Program pg(ct, source);

	pg.build(dev);

	ASSERT_EQ(pg.getBuildInfo<CL_PROGRAM_BUILD_LOG>(dev), "\n");
	return pg;
}
#endif  // NO_EMBEDDED_CL
Kernel 
clboost::make_kernel(const Program& prog, const std::string& class_name)
{
	return Kernel(prog, class_name.c_str());
}



void 
clboost::enq_q(CommandQueue& q, const Kernel& kernel, Event& this_event, const vector<Event>& wait_ev, const int global_size, const int local_size)
{
	ASSERT_UEQ(global_size, 0);
	q.enqueueNDRangeKernel(kernel, NullRange, NDRange(global_size), (local_size==NULL?NullRange:NDRange(local_size)), &wait_ev, &this_event);
	q.finish();
	return;
}
void 
clboost::enq_q(CommandQueue& q, const Kernel& kernel, const int global_size, const int local_size)
{
	ASSERT_UEQ(global_size, 0);
	q.enqueueNDRangeKernel(kernel, NullRange, NDRange(global_size), (local_size == NULL ? NullRange : NDRange(local_size)));
	return;
}


Event
clboost::make_event() {
	return Event::Event();
}


