import * as THREE from "three";
import { Water } from "three/addons/objects/Water.js";
import { Sky } from "three/addons/objects/Sky.js";

const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera(
  75,
  window.innerWidth / window.innerHeight,
  0.1,
  2000
);
const renderer = new THREE.WebGLRenderer({ antialias: true });
renderer.setSize(window.innerWidth, window.innerHeight);
renderer.toneMapping = THREE.ACESFilmicToneMapping;
document.body.appendChild(renderer.domElement);

const waterGeometry = new THREE.PlaneGeometry(10000, 10000);
const water = new Water(waterGeometry, {
  textureWidth: 512,
  textureHeight: 512,
  waterNormals: new THREE.TextureLoader().load(
    "https://threejs.org/examples/textures/waternormals.jpg",
    (texture) => (texture.wrapS = texture.wrapT = THREE.RepeatWrapping)
  ),
  sunDirection: new THREE.Vector3(),
  sunColor: 0xffebb2,
  waterColor: 0x2f4a6e,
  distortionScale: 4.5,
  fog: scene.fog !== undefined,
});
water.rotation.x = -Math.PI / 2;
scene.add(water);

const sky = new Sky();
sky.scale.setScalar(10000);
scene.add(sky);

const skyUniforms = sky.material.uniforms;
skyUniforms["turbidity"].value = 8;
skyUniforms["rayleigh"].value = 3;
skyUniforms["mieCoefficient"].value = 0.005;
skyUniforms["mieDirectionalG"].value = 0.8;

const goldenLight = new THREE.DirectionalLight(0xffe4a6, 1.2);
goldenLight.position.set(-100, 100, 100);
scene.add(goldenLight);
scene.add(new THREE.AmbientLight(0x443355));

camera.position.set(0, 50, 300);
camera.lookAt(0, 0, 0);

let time = 0;
function animate() {
  requestAnimationFrame(animate);

  time += 0.001;
  water.material.uniforms["time"].value += 1.0 / 60.0;

  const goldenHue = Math.sin(time * 0.5) * 0.05 + 0.12;
  water.material.uniforms["sunColor"].value.setHSL(goldenHue, 0.8, 0.7);

  renderer.render(scene, camera);
}

window.addEventListener("resize", () => {
  camera.aspect = window.innerWidth / window.innerHeight;
  camera.updateProjectionMatrix();
  renderer.setSize(window.innerWidth, window.innerHeight);
});

animate();
