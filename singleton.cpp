class App { // Singleton
public:
    static App *instance();
    virtual void op();


protected:
    App();
    virtual ~App();
    static App *instance_;
};

App *App::instance() {
    if (!instance_) {
        Guard<Mutex> guard(lock_);
        if (!instance_)
            instance_ = new App;
    }
    return instance_;
}
