CXXFLAGS=-c -std=c++11 -O -g -w
all: DWsim
DWsim:configuration.o wintolinux.o op_common.o dataTypeModeling.o localBufferModeling.o common.o \
fileVariant.o options.o ps_pipeline.o print.o list.o stackOP.o printINAddr.o print_error.o \
ps_inst.o bandwith_monitor.o pulse_error.o fixcomp.o memop.o mctrl.o data_reuse.o operation_type.o \
pu.o pl_kernel.o convb.o printR.o print_mat.o print_bandwith.o print_ins_to_binary.o \
reportall.o sim.o main.o
	g++ -o pulsesim configuration.o wintolinux.o op_common.o dataTypeModeling.o localBufferModeling.o common.o \
fileVariant.o options.o ps_pipeline.o print.o list.o stackOP.o printINAddr.o print_error.o \
ps_inst.o bandwith_monitor.o pulse_error.o fixcomp.o memop.o mctrl.o data_reuse.o operation_type.o \
pu.o pl_kernel.o convb.o printR.o print_mat.o print_bandwith.o print_ins_to_binary.o \
reportall.o sim.o main.o

configuration.o:configuration.cpp configuration.h
	g++ $(CXXFLAGS)  configuration.cpp -o configuration.o
wintolinux.o:wintolinux.cpp wintolinux.h
	g++ $(CXXFLAGS) wintolinux.cpp -o wintolinux.o
op_common.o:op_common.cpp op_common.h
	g++ $(CXXFLAGS)  op_common.cpp -o op_common.o
dataTypeModeling.o:dataTypeModeling.cpp dataTypeModeling.h op_common.h
	g++ $(CXXFLAGS)  dataTypeModeling.cpp -o dataTypeModeling.o
localBufferModeling.o:localBufferModeling.cpp localBufferModeling.h configuration.h
	g++ $(CXXFLAGS)  localBufferModeling.cpp -o localBufferModeling.o
common.o:common.cpp common.h localBufferModeling.h
	g++ $(CXXFLAGS)  common.cpp -o common.o
fileVariant.o:fileVariant.cpp fileVariant.h
	g++ $(CXXFLAGS)  fileVariant.cpp -o fileVariant.o
options.o:options.cpp options.h configuration.h common.h fileVariant.h
	g++ $(CXXFLAGS) options.cpp -o options.o
ps_pipeline.o:ps_pipeline.cpp ps_pipeline.h configuration.h regsModeling.h memModeling.h insModeling.h
	g++ $(CXXFLAGS)  ps_pipeline.cpp -o ps_pipeline.o
print.o:print.cpp print.h common.h fileVariant.h ps_pipeline.h options.h localBufferModeling.h
	g++ $(CXXFLAGS)  print.cpp -o print.o
list.o:list.cpp list.h
	g++ $(CXXFLAGS)  list.cpp -o list.o
stackOP.o:stackOP.cpp stackOP.h
	g++ $(CXXFLAGS)  stackOP.cpp -o stackOP.o
printINAddr.o:printINAddr.cpp printINAddr.h
	g++ $(CXXFLAGS)  printINAddr.cpp -o printINAddr.o
print_error.o:print_error.cpp print_error.h
	g++ $(CXXFLAGS)  print_error.cpp -o print_error.o
ps_inst.o:ps_inst.cpp ps_inst.h op_common.h fileVariant.h print_error.h ps_pipeline.h dataTypeModeling.h
	g++ $(CXXFLAGS)  ps_inst.cpp -o ps_inst.o
bandwith_monitor.o:bandwith_monitor.cpp bandwith_monitor.h ps_pipeline.h
	g++ $(CXXFLAGS)  bandwith_monitor.cpp -o bandwith_monitor.o
pulse_error.o:pulse_error.cpp pulse_error.h
	g++ $(CXXFLAGS)  pulse_error.cpp -o pulse_error.o
fixcomp.o:fixcomp.cpp fixcomp.h bandwith_monitor.h pulse_error.h
	g++ $(CXXFLAGS)  fixcomp.cpp -o fixcomp.o
memop.o:memop.cpp memop.h ps_pipeline.h
	g++ $(CXXFLAGS)  memop.cpp -o memop.o
mctrl.o:mctrl.cpp mctrl.h ps_pipeline.h memop.h fileVariant.h
	g++ $(CXXFLAGS)  mctrl.cpp -o mctrl.o
data_reuse.o:data_reuse.cpp data_reuse.h
	g++ $(CXXFLAGS)  data_reuse.cpp -o data_reuse.o
operation_type.o:operation_type.cpp operation_type.h
	g++ $(CXXFLAGS)  operation_type.cpp -o operation_type.o
pu.o:pu.cpp pu.h ps_pipeline.h fixcomp.h print_error.h mctrl.h localBufferModeling.h common.h bandwith_monitor.h data_reuse.h operation_type.h
	g++ $(CXXFLAGS)  pu.cpp -o pu.o
pl_kernel.o:pl_kernel.cpp pl_kernel.h ps_pipeline.h configuration.h print.h list.h options.h convb.h printINAddr.h localBufferModeling.h list.h stackOP.h ps_pipeline.h ps_inst.h print_error.h pu.h
	g++ $(CXXFLAGS)  pl_kernel.cpp -o pl_kernel.o
convb.o:convb.cpp convb.h ps_pipeline.h pl_kernel.h ps_inst.h
	g++ $(CXXFLAGS)  convb.cpp -o convb.o
printR.o:printR.cpp printR.h ps_pipeline.h printR.h
	g++ $(CXXFLAGS)  printR.cpp -o printR.o
print_mat.o:print_mat.cpp print_mat.h ps_pipeline.h
	g++ $(CXXFLAGS)  print_mat.cpp -o print_mat.o
print_bandwith.o:print_bandwith.cpp print_bandwith.h bandwith_monitor.h
	g++ $(CXXFLAGS)  print_bandwith.cpp -o print_bandwith.o
print_ins_to_binary.o:print_ins_to_binary.cpp print_ins_to_binary.h
	g++ $(CXXFLAGS)  print_ins_to_binary.cpp -o print_ins_to_binary.o
reportall.o:reportall.cpp reportall.h print.h ps_pipeline.h data_reuse.h operation_type.h bandwith_monitor.h reportString.h
	g++ $(CXXFLAGS)  reportall.cpp -o reportall.o
sim.o:sim.cpp sim.h configuration.h convb.h mctrl.h localBufferModeling.h ps_inst.h printR.h print_mat.h print_bandwith.h pulse_error.h printINAddr.h pl_kernel.h print.h data_reuse.h fileVariant.h print_ins_to_binary.h bandwith_monitor.h operation_type.h reportall.h
	g++ $(CXXFLAGS)  sim.cpp -o sim.o
main.o:main.cpp options.h fileVariant.h sim.h dataTypeModeling.h
	g++ $(CXXFLAGS)  main.cpp -o main.o
clean:
	rm -rf DWsim configuration.o wintolinux.o op_common.o dataTypeModeling.o localBufferModeling.o common.o \
fileVariant.o options.o ps_pipeline.o print.o list.o stackOP.o printINAddr.o print_error.o \
ps_inst.o bandwith_monitor.o pulse_error.o fixcomp.o memop.o mctrl.o data_reuse.o operation_type.o \
pu.o pl_kernel.o convb.o printR.o print_mat.o print_bandwith.o print_ins_to_binary.o \
reportall.o sim.o main.o
