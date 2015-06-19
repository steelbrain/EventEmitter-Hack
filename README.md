EventEmitter-Hack
===============
EventEmitter is a super-lightweight event emitter for [Hack][Hack]. You can use it to get a NodeJS's EventEmitter or jQuery Events like feeling in your app.

### Usage
You can either use an instance of EventEmitter or Extend It
```hack
// As an Instance
$Inst = new EventEmitter();
$Inst->on('Init', function(string $Info){
  echo "OnInit: $Info\n";
});
$Inst->emit('Init', 'Test');
```
```hack
// By extending it
class MyApp extends EventEmitter{
  public function __construct(){
    $this->on('Scan', inst_meth($this, 'Scan'))
  }
  public function Scan():void{
    echo "Scanning\n";
  }
}
$MyApp = new MyApp();
$MyApp->emit('Scan');
```

### License
This project is licensed under the terms of MIT License.
[Hack]:http://hacklang.org