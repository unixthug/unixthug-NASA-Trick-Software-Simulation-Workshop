%module top

%{
#include "../S_source.hh"

extern SysSimObject trick_sys ;
extern MonteCarloSimObject trick_mc ;
extern MemoryManagerSimObject trick_mm ;
extern CheckPointRestartSimObject trick_cpr ;
extern SieSimObject trick_sie ;
extern CommandLineArgumentsSimObject trick_cmd_args ;
extern MessageSimObject trick_message ;
extern JITSimObject trick_jit ;
extern InputProcessorSimObject trick_ip ;
extern EventManagerSimObject trick_em ;
extern VariableServerSimObject trick_vs ;
extern DataRecordDispatcherSimObject trick_data_record ;
extern RTSyncSimObject trick_real_time ;
extern FrameLogSimObject trick_frame_log;
extern MasterSlaveSimObject trick_master_slave ;
extern InstrumentationSimObject trick_instruments ;
extern InjectorSimObject trick_inject ;
extern ZeroconfSimObject trick_zero_conf ;
extern UnitTestSimObject trick_utest ;
extern UdUnitsSimObject trick_udunits;
extern SubmarineSimObject dyn;
extern IntegLoopSimObject dyn_integloop ;

%}

%import "build/home/caci114/trick_sims/SIM_submarine/S_source_py.i"

extern SysSimObject trick_sys ;
extern MonteCarloSimObject trick_mc ;
extern MemoryManagerSimObject trick_mm ;
extern CheckPointRestartSimObject trick_cpr ;
extern SieSimObject trick_sie ;
extern CommandLineArgumentsSimObject trick_cmd_args ;
extern MessageSimObject trick_message ;
extern JITSimObject trick_jit ;
extern InputProcessorSimObject trick_ip ;
extern EventManagerSimObject trick_em ;
extern VariableServerSimObject trick_vs ;
extern DataRecordDispatcherSimObject trick_data_record ;
extern RTSyncSimObject trick_real_time ;
extern FrameLogSimObject trick_frame_log;
extern MasterSlaveSimObject trick_master_slave ;
extern InstrumentationSimObject trick_instruments ;
extern InjectorSimObject trick_inject ;
extern ZeroconfSimObject trick_zero_conf ;
extern UnitTestSimObject trick_utest ;
extern UdUnitsSimObject trick_udunits;
extern SubmarineSimObject dyn;
extern IntegLoopSimObject dyn_integloop ;
