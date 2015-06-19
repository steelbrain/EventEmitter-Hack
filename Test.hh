<?hh
require(__DIR__.'/Source/EventEmitter.hh');
type SomeShape = shape('Hey' => string);
function Main():void{
  $Emitter = new EventEmitter();
  $Emitter->on('Integer', function(int $Value){
    var_dump($Value);
  });
  $Emitter->emit('Integer', 1);
  $Emitter->on('String', function(string $Value){
    var_dump($Value);
  });
  $Emitter->emit('String', 'Hey There');
  $Emitter->on('Something', function(SomeShape $Value){
    var_dump($Value);
  });
  $Emitter->emit('Something', shape('Hey' => 'There'));
}
Main();
