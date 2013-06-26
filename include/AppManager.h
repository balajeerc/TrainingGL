#pragma once

namespace TrainingGL
{
    //  \brief  Class that starts and handles main thread of app
    //  \detail Control center of this application
    class AppManager
    {
    public:
        /// \brief  Constructor
        AppManager();

        /// \brief  Destructor
        ~AppManager();

        /// \brief  Starts application thread
        void initApplication(int argc, char* argv[]);

        /// \brief  Main loop for the application
        void update();

    protected:
        static AppManager* _mainInstance;

        /// brief   Glut annoyingly requires a C function for all its callbacks
        ///
        static void OnDisplay();
    };
}
