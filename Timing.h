#pragma once

#ifndef PEOT_DEMO_TIMING_H
#define PEOT_DEMO_TIMING_H

  /**
   * Represents all the information that the demo might need about the
   * timing of the game: current time, fps, frame number, and so on.
   */
struct TimingData
{
    //current render frame (just increments)
    unsigned frameNumber;

    //The timestamp when the last frame ended. (milliseconds)     
    unsigned lastFrameTimestamp;
 
    //The duration of the last frame in milliseconds.
    unsigned lastFrameDuration;

   
    //clockstamp of the end of the last frame

    unsigned long lastFrameClockstamp;

    
    //duration of the last frame in clock ticks
    unsigned long lastFrameClockTicks;


    //is rendering paused? flag
    bool isPaused;


    /**
     * recency weighted avg of the frame time, calculated
     * from frame durations
     */
    double averageFrameDuration;

    /**
     * reciprocal of avg frame duration giving the mean
     * fps over a recency weighted average
     */
    float fps;

    //grabs global timing data object
    static TimingData& get();

    //called on every frame update
    static void update();

 
    static void init();

    
    static void deinit();


    //Gets the global system time (milliseconds)
    static unsigned getTime();

    //Gets clock ticks since process start.
    static unsigned long getClock();


private:
    // getter methods can access these instances
    TimingData() {}
    TimingData(const TimingData&) {}
    TimingData& operator=(const TimingData&);
};


#endif

