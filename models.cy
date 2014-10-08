Animation
	Import string
	Images []AnimationSlide

AnimationSlide
	Interval int
	Image    Image

AnimLayer
	Point     Point
	Animation string # Animation import

Point
	X int
	Y int

Size
	Width  int
	Height int

Bounds
	X      int
	Y      int
	Width  int
	Height int

SaveVariables
	Vars map[string]unknown

SpriteSheetImage
	SrcBounds Bounds

SpriteSheet
	TilesWide        int
	TilesHigh        int
	TileWidth        int
	TileHeight       int
	SrcFile          string
	Images           map[int]SpriteSheetImage
	ImageIdIterator  int
	RecycledImageIds []int

Image
	# Path to the sprite sheet the image is from
	SpriteSheet string
	ImgId       int
	DefaultSize Size

SpriteClass
	AnimLayers [][]AnimLayer
	SpriteType int # (Inanimate = 1, Person = 2, Creature = 3)
	Attributes string # content differs depending on SpriteType

Sprite
	Id          string
	SpriteClass string
	Motion      int # (Still = 1, Walking = 2)
	Facing      int # (North = 1, South = 2, East = 3, West = 4)
	SpriteType  int # (Inanimate = 1, Person = 2, Creature = 3)
	Data        string # content differs depending on SpriteType

TileClass
	Import      string
	TerrainType int
	LowerAnim   AnimLayer
	UpperAnim   AnimLayer

Tile
	TileClass TileClass
	Occupant  Sprite

World
	Zones []ZoneInstance

Zone
	Tiles [][][]Tile

ZoneHeader
	Zone      string
	TilesWide int
	TilesHigh int
	Layers    int

ZoneInstance
	AccessorID string
	ZoneHeader string
	Address    Point

PersonClass
	Import    string
	Title     map[string]string
	# [x][y]: x - (North/South/East/West), y - (Still = 0, Walking = 1)
	Overhead  [][]AnimLayer
	FrontView Animation
	BackView  Animation

Person
	PersonClass PersonClass
	Name        map[string]string
	Creatures   []string # paths to the Creatures this Person owns
