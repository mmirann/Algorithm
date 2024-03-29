# A playlist is considered a repeating playlist if any of the songs contain a
# reference to a previous song in the playlist. Otherwise, the playlist will end
# with the last song which points to None.
# Implement a fucntion is_repeating_playlist that, efficiently with respect to
# time used, returns true if a playlist is repeating or false if it is not.

class Song:
    def __init__(self, name):
        self.name = name
        self.next = None

    def next_song(self, song):
        self.next = song

    def is_repeating_playlist(self):
        """
        :returns: (bool) True if the playlist is repeating, False if not.
        """
        songs = set()
        next_song = self
        while next_song:
            if next_song.name in songs:
                return True
            else:
                songs.add(next_song.name)
                next_song = next_song.next or None

        return False


first = Song("Hello")
second = Song("Eye of the tiger")

first.next_song(second)
second.next_song(first)

print(first.is_repeating_playlist())
