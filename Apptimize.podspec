Pod::Spec.new do |s|
  s.name                   = "Apptimize"
  s.version                = "1.0"
  s.summary                = "Fake Apptimize"
  s.homepage               = "http://www.fake.com"
  s.license                = { :type => "MIT" }
  s.author                 = { 'jefflopes' => 'jlopes@monkeycity.org' }
  s.source                 = { :git => 'https://github.com/jefflopes/FakeApptimize.git', :tag => s.version.to_s }
  s.ios.deployment_target  = '12.0'
  s.source_files           = 'Apptimize/Apptimize/*.{h,m}'
end