//
//  HelloWorldLayer.h
//  BadgerVsWalrus
//
//  Created by Stefan Church on 22/10/2011.
//  Copyright Stefan Church 2011. All rights reserved.
//

#import "cocos2d.h"
#import "GameOverLayer.h"
#import "Game.h"
#import "NetworkManager.h"
#import "CountDownLayer.h"
#import "NetworkLayer.h"
#import "TapInterpreter.h"
#import "Viewport.h"

typedef enum {
    kDot = 0,
    kDash = 1
} TickerElementType;

@interface GameLayer : NetworkLayer<NetworkManagerGameDelegate, CountdownDelegate, TapInterpreterDelegte>
{
    CCSprite *_player1;
    CCSprite *_player2;
    CCSprite *_player1Selected;
    CCSprite *_player2Selected;
    CCSprite *_beatIndicator;
    CCSprite *_tapButton;
    CCSprite *_flashSprite;
    CCAnimation *_flashAnimation;
    CCLabelTTF *_timeLabel;
    GameState _gameState;
    Animal _choosenAnimal;
    float _gameTime;
    NSTimeInterval _tapStartTime;
    TapInterpreter *_tapInterpreter;
    NSMutableArray *_tickers;
    Viewport *_tickerViewport;
}

@property (nonatomic, retain) CCSprite *player1;
@property (nonatomic, retain) CCSprite *player2;
@property (nonatomic, retain) CCSprite *player1Selected;
@property (nonatomic, retain) CCSprite *player2Selected;
@property (nonatomic, retain) CCSprite *beatIndicator;
@property (nonatomic, retain) CCSprite *tapButton;
@property (nonatomic, retain) CCSprite *flashSprite;
@property (nonatomic, retain) CCAnimation *flashAnimation;
@property (nonatomic, retain) CCLabelTTF *timeLabel;
@property (nonatomic, assign) Animal choosenAnimal;
@property (nonatomic, readonly) CCSprite *humanPlayer;
@property (nonatomic, readonly) CCSprite *otherPlayer;
@property (nonatomic, retain) TapInterpreter *tapInterpreter;
@property (nonatomic, retain) NSMutableArray *tickers;
@property (nonatomic, retain) Viewport *tickerViewport;

- (void)playTickerFlash;

+(CCScene *) sceneWithChosenAnimal:(Animal)animal;
+(CCScene *) sceneWithChosenAnimal:(Animal)animal isNetworkGame:(BOOL)isNetworkGame;

@end
