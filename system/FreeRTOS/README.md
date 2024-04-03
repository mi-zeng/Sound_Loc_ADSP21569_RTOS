This Readme is the Quick Starter Guide for the FreeRTOS Addin.
1. Install the FreeRTOS Addin and add it into project, please refer to this page
   https://wiki.analog.com/resources/tools-software/freertos/freertos-addin

2. Added files and edited code 
   a) Several files will be added under the folder CustomizableFreeRTOSSources 
      All of the files within this folder are generated when the add-in is added to a project, they will NOT be regenerated (if they already exist in the project).
   b) The original main() function will be refactored, to add three functions as below, 
    	/* Configure the hardware as necessary to run this demo. */
    	prvSetupHardware();

    	/* Start the tasks defined within this file which are specific to this demo. */
    	vCustomizeTasksFun();

    	/* Start the scheduler. */
    	vTaskStartScheduler();
        
      The function vTaskStartScheduler() never returns, so any code after this function call will be invalid. And NOT to use SSL/DD before the scheduler is invoked, such as Initialization function. They should be done in scheduler after timer tasks.
   c) And the basic task implementation is in FreeRTOSUserApplication.c
      The files under CustomizableFreeRTOSSources is NOT removed when the add-in is removed from the project, this is to protect any functional code.

3. Run projects on Cortex-A
   The semihosting I/O mechanism, which writes to the CCES console during debug sessions, uses SWI interrupts. This is incompatible with default GCC-compiled I/O code which also uses SWI interrupts. For this reason, stdio function calls initiated on the ARM core are routed out over UART instead and shall be read with a serial terminal external to CCES.
   Importantly, note that:
   a) This is currently only supported within FreeRTOS threads, any stdio function call performed outwith a thread will crash the application.
   b) If need to use other peripherals, user should take care not to change the power service clock rate (which is set in the UART I/O device).
   c) Before running the example, please setup the serial terminal of user choice to read the Cortex core output from the UART to USB connection on the HOST PC.
   d) Disable the semihosting function in Automatic Breakpoints before running application.

4. The specific getting started guide for platform we support 
   //the link for wiki page 

