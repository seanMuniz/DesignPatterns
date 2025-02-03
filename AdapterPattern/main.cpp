#include <iostream>
#include <string>

// This is the main interface that the modernMediaPlayer and
// the interface must inherit from. This is the CLIENT INTERFACE 
class MediaPlayer {
    public: 
        virtual void play(const std::string& filename) const = 0; 
        virtual ~MediaPlayer() = default;
};

// This is the CLIENT that will implement the client interface, 
class ModernMediaPlayer : public MediaPlayer {
    public: 
        void play(const std::string& filename) const override {
            std::cout << "Playing modern media file: " << filename << std::endl; 
        }
};

// This is the SERVICE. It does not inherit from anything and this is what we 
// will need an adapter for. 
class LegacyMediaPlayer {
    public: 
        void playAVI(const std::string& filename) const {
            std::cout << "Playing AVI file: " << filename << std::endl; 
        }
};

// This is the ADAPTER for the LegacyMediaPlayer. This is also the adapter which inherits 
// from the MediaPlayer = client interface. 
class MediaPlayerAdapter: public MediaPlayer {
    private: 
        LegacyMediaPlayer* legacyPlayer; 
    public: 
        explicit MediaPlayerAdapter(LegacyMediaPlayer* player) : legacyPlayer(player) {}
        void play(const std::string& filename) const override{
            std::cout << "Adapter converting request for file:" << filename << std::endl;
            legacyPlayer->playAVI(filename);
        }
};



int main() {
    // Create a modern media player
    MediaPlayer* modernPlayer = new ModernMediaPlayer();
    modernPlayer->play("video.mp4");

    // Create a legacy media player
    LegacyMediaPlayer* legacyPlayer = new LegacyMediaPlayer();

    // Use the adapter to make the legacy player compatible with the MediaPlayer interface
    MediaPlayer* adaptedPlayer = new MediaPlayerAdapter(legacyPlayer);
    adaptedPlayer->play("video.avi");

    // Clean up
    delete modernPlayer;
    delete adaptedPlayer;
    delete legacyPlayer;

    return 0;
}