<?hh
class EventEmitter{
  public Map<string, Vector<(function(string):void)>> $Callbacks = Map{};
  public function on(string $Event, (function(string):void) $Callback):this{
    if(!$this->Callbacks->contains($Event)){
      $this->Callbacks->set($Event, Vector{});
    }
    $this->Callbacks->get($Event)?->add($Callback);
    return $this;
  }
  public function once(string $Event, (function(string):void) $Callback):this{
    if(!$this->Callbacks->contains($Event)){
      $this->Callbacks->set($Event, Vector{});
    }
    $WrapperCB = null;
    $WrapperCB = function(string $Info) use($Callback, $Event, &$WrapperCB) {
      $Callback($Info);
      $this->off($Event, $WrapperCB);
    };
    $this->Callbacks->get($Event)?->add($WrapperCB);
    return $this;
  }
  public function off(string $Event, ?(function(string):void) $Callback):this{
    if($this->Callbacks->contains($Event)){
      if($Callback === null){
        $this->Callbacks->remove($Event);
      } else {
        $Index = $this->Callbacks->get($Event)?->linearSearch($Callback);
        if($Index !== null && $Index !== -1){
          $this->Callbacks->get($Event)?->removeKey($Index);
        }
      }
    }
    return $this;
  }
  public function emit(string $Event, string $Args):this{
    $Vector = $this->Callbacks->contains($Event) ? $this->Callbacks->get($Event) : null;
    if($Vector !== null){
      foreach($Vector as $Callback){
        $Callback($Args);
      }
    }
    return $this;
  }
}
