Pod::Spec.new do |s|
  s.name             = 'EPCalloutView'
  s.version          = '0.1.0'
  s.summary          = 'General-purpose callout/popover for iOS'
  s.homepage         = 'https://github.com/rosslebeau/EPCalloutView'
  s.source           = { :git => 'https://github.com/rosslebeau/EPCalloutView.git', :tag => s.version }
  s.license          = 'MIT'
  s.author           = { 'Ross LeBeau' => 'ross.lebeau@gmail.com' }
  s.social_media_url = 'https://twitter.com/rosslebeau'

  s.platform     = :ios, '7.0'
  s.requires_arc = true

  s.source_files = 'Source/**/*.{h,m}'
  s.resource_bundle = { 'EPCalloutView' => 'Resources/*' }
end
